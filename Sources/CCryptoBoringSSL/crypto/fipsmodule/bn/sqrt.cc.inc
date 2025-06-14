// Copyright 2000-2016 The OpenSSL Project Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <CCryptoBoringSSL_bn.h>

#include <CCryptoBoringSSL_err.h>

#include "internal.h"


BIGNUM *BN_mod_sqrt(BIGNUM *in, const BIGNUM *a, const BIGNUM *p, BN_CTX *ctx) {
  // Compute a square root of |a| mod |p| using the Tonelli/Shanks algorithm
  // (cf. Henri Cohen, "A Course in Algebraic Computational Number Theory",
  // algorithm 1.5.1). |p| is assumed to be a prime.

  BIGNUM *ret = in;
  int err = 1;
  int r;
  BIGNUM *A, *b, *q, *t, *x, *y;
  int e, i, j;

  if (!BN_is_odd(p) || BN_abs_is_word(p, 1)) {
    if (BN_abs_is_word(p, 2)) {
      if (ret == NULL) {
        ret = BN_new();
      }
      if (ret == NULL ||
          !BN_set_word(ret, BN_is_bit_set(a, 0))) {
        if (ret != in) {
          BN_free(ret);
        }
        return NULL;
      }
      return ret;
    }

    OPENSSL_PUT_ERROR(BN, BN_R_P_IS_NOT_PRIME);
    return NULL;
  }

  if (BN_is_zero(a) || BN_is_one(a)) {
    if (ret == NULL) {
      ret = BN_new();
    }
    if (ret == NULL ||
        !BN_set_word(ret, BN_is_one(a))) {
      if (ret != in) {
        BN_free(ret);
      }
      return NULL;
    }
    return ret;
  }

  bssl::BN_CTXScope scope(ctx);
  A = BN_CTX_get(ctx);
  b = BN_CTX_get(ctx);
  q = BN_CTX_get(ctx);
  t = BN_CTX_get(ctx);
  x = BN_CTX_get(ctx);
  y = BN_CTX_get(ctx);
  if (y == NULL) {
    goto end;
  }

  if (ret == NULL) {
    ret = BN_new();
  }
  if (ret == NULL) {
    goto end;
  }

  // A = a mod p
  if (!BN_nnmod(A, a, p, ctx)) {
    goto end;
  }

  // now write  |p| - 1  as  2^e*q  where  q  is odd
  e = 1;
  while (!BN_is_bit_set(p, e)) {
    e++;
  }
  // we'll set  q  later (if needed)

  if (e == 1) {
    // The easy case:  (|p|-1)/2  is odd, so 2 has an inverse
    // modulo  (|p|-1)/2,  and square roots can be computed
    // directly by modular exponentiation.
    // We have
    //     2 * (|p|+1)/4 == 1   (mod (|p|-1)/2),
    // so we can use exponent  (|p|+1)/4,  i.e.  (|p|-3)/4 + 1.
    if (!BN_rshift(q, p, 2)) {
      goto end;
    }
    q->neg = 0;
    if (!BN_add_word(q, 1) ||
        !BN_mod_exp_mont(ret, A, q, p, ctx, NULL)) {
      goto end;
    }
    err = 0;
    goto vrfy;
  }

  if (e == 2) {
    // |p| == 5  (mod 8)
    //
    // In this case  2  is always a non-square since
    // Legendre(2,p) = (-1)^((p^2-1)/8)  for any odd prime.
    // So if  a  really is a square, then  2*a  is a non-square.
    // Thus for
    //      b := (2*a)^((|p|-5)/8),
    //      i := (2*a)*b^2
    // we have
    //     i^2 = (2*a)^((1 + (|p|-5)/4)*2)
    //         = (2*a)^((p-1)/2)
    //         = -1;
    // so if we set
    //      x := a*b*(i-1),
    // then
    //     x^2 = a^2 * b^2 * (i^2 - 2*i + 1)
    //         = a^2 * b^2 * (-2*i)
    //         = a*(-i)*(2*a*b^2)
    //         = a*(-i)*i
    //         = a.
    //
    // (This is due to A.O.L. Atkin,
    // <URL:
    //http://listserv.nodak.edu/scripts/wa.exe?A2=ind9211&L=nmbrthry&O=T&P=562>,
    // November 1992.)

    // t := 2*a
    if (!bn_mod_lshift1_consttime(t, A, p, ctx)) {
      goto end;
    }

    // b := (2*a)^((|p|-5)/8)
    if (!BN_rshift(q, p, 3)) {
      goto end;
    }
    q->neg = 0;
    if (!BN_mod_exp_mont(b, t, q, p, ctx, NULL)) {
      goto end;
    }

    // y := b^2
    if (!BN_mod_sqr(y, b, p, ctx)) {
      goto end;
    }

    // t := (2*a)*b^2 - 1
    if (!BN_mod_mul(t, t, y, p, ctx) ||
        !BN_sub_word(t, 1)) {
      goto end;
    }

    // x = a*b*t
    if (!BN_mod_mul(x, A, b, p, ctx) ||
        !BN_mod_mul(x, x, t, p, ctx)) {
      goto end;
    }

    if (!BN_copy(ret, x)) {
      goto end;
    }
    err = 0;
    goto vrfy;
  }

  // e > 2, so we really have to use the Tonelli/Shanks algorithm.
  // First, find some  y  that is not a square.
  if (!BN_copy(q, p)) {
    goto end;  // use 'q' as temp
  }
  q->neg = 0;
  i = 2;
  do {
    // For efficiency, try small numbers first;
    // if this fails, try random numbers.
    if (i < 22) {
      if (!BN_set_word(y, i)) {
        goto end;
      }
    } else {
      if (!BN_pseudo_rand(y, BN_num_bits(p), 0, 0)) {
        goto end;
      }
      if (BN_ucmp(y, p) >= 0) {
        if (BN_usub(y, y, p)) {
          goto end;
        }
      }
      // now 0 <= y < |p|
      if (BN_is_zero(y)) {
        if (!BN_set_word(y, i)) {
          goto end;
        }
      }
    }

    r = bn_jacobi(y, q, ctx);  // here 'q' is |p|
    if (r < -1) {
      goto end;
    }
    if (r == 0) {
      // m divides p
      OPENSSL_PUT_ERROR(BN, BN_R_P_IS_NOT_PRIME);
      goto end;
    }
  } while (r == 1 && ++i < 82);

  if (r != -1) {
    // Many rounds and still no non-square -- this is more likely
    // a bug than just bad luck.
    // Even if  p  is not prime, we should have found some  y
    // such that r == -1.
    OPENSSL_PUT_ERROR(BN, BN_R_TOO_MANY_ITERATIONS);
    goto end;
  }

  // Here's our actual 'q':
  if (!BN_rshift(q, q, e)) {
    goto end;
  }

  // Now that we have some non-square, we can find an element
  // of order  2^e  by computing its q'th power.
  if (!BN_mod_exp_mont(y, y, q, p, ctx, NULL)) {
    goto end;
  }
  if (BN_is_one(y)) {
    OPENSSL_PUT_ERROR(BN, BN_R_P_IS_NOT_PRIME);
    goto end;
  }

  // Now we know that (if  p  is indeed prime) there is an integer
  // k,  0 <= k < 2^e,  such that
  //
  //      a^q * y^k == 1   (mod p).
  //
  // As  a^q  is a square and  y  is not,  k  must be even.
  // q+1  is even, too, so there is an element
  //
  //     X := a^((q+1)/2) * y^(k/2),
  //
  // and it satisfies
  //
  //     X^2 = a^q * a     * y^k
  //         = a,
  //
  // so it is the square root that we are looking for.

  // t := (q-1)/2  (note that  q  is odd)
  if (!BN_rshift1(t, q)) {
    goto end;
  }

  // x := a^((q-1)/2)
  if (BN_is_zero(t)) {  // special case: p = 2^e + 1
    if (!BN_nnmod(t, A, p, ctx)) {
      goto end;
    }
    if (BN_is_zero(t)) {
      // special case: a == 0  (mod p)
      BN_zero(ret);
      err = 0;
      goto end;
    } else if (!BN_one(x)) {
      goto end;
    }
  } else {
    if (!BN_mod_exp_mont(x, A, t, p, ctx, NULL)) {
      goto end;
    }
    if (BN_is_zero(x)) {
      // special case: a == 0  (mod p)
      BN_zero(ret);
      err = 0;
      goto end;
    }
  }

  // b := a*x^2  (= a^q)
  if (!BN_mod_sqr(b, x, p, ctx) ||
      !BN_mod_mul(b, b, A, p, ctx)) {
    goto end;
  }

  // x := a*x    (= a^((q+1)/2))
  if (!BN_mod_mul(x, x, A, p, ctx)) {
    goto end;
  }

  while (1) {
    // Now  b  is  a^q * y^k  for some even  k  (0 <= k < 2^E
    // where  E  refers to the original value of  e,  which we
    // don't keep in a variable),  and  x  is  a^((q+1)/2) * y^(k/2).
    //
    // We have  a*b = x^2,
    //    y^2^(e-1) = -1,
    //    b^2^(e-1) = 1.
    if (BN_is_one(b)) {
      if (!BN_copy(ret, x)) {
        goto end;
      }
      err = 0;
      goto vrfy;
    }

    // Find the smallest i, 0 < i < e, such that b^(2^i) = 1
    for (i = 1; i < e; i++) {
      if (i == 1) {
        if (!BN_mod_sqr(t, b, p, ctx)) {
          goto end;
        }
      } else {
        if (!BN_mod_mul(t, t, t, p, ctx)) {
          goto end;
        }
      }
      if (BN_is_one(t)) {
        break;
      }
    }
    // If not found, a is not a square or p is not a prime.
    if (i >= e) {
      OPENSSL_PUT_ERROR(BN, BN_R_NOT_A_SQUARE);
      goto end;
    }

    // t := y^2^(e - i - 1)
    if (!BN_copy(t, y)) {
      goto end;
    }
    for (j = e - i - 1; j > 0; j--) {
      if (!BN_mod_sqr(t, t, p, ctx)) {
        goto end;
      }
    }
    if (!BN_mod_mul(y, t, t, p, ctx) ||
        !BN_mod_mul(x, x, t, p, ctx) ||
        !BN_mod_mul(b, b, y, p, ctx)) {
      goto end;
    }

    // e decreases each iteration, so this loop will terminate.
    assert(i < e);
    e = i;
  }

vrfy:
  if (!err) {
    // Verify the result. The input might have been not a square.
    if (!BN_mod_sqr(x, ret, p, ctx)) {
      err = 1;
    }

    if (!err && 0 != BN_cmp(x, A)) {
      OPENSSL_PUT_ERROR(BN, BN_R_NOT_A_SQUARE);
      err = 1;
    }
  }

end:
  if (err) {
    if (ret != in) {
      BN_clear_free(ret);
    }
    ret = NULL;
  }
  return ret;
}
