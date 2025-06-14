// Copyright 2006-2017 The OpenSSL Project Authors. All Rights Reserved.
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

#include <CCryptoBoringSSL_rsa.h>

#include <CCryptoBoringSSL_evp.h>


int RSA_print(BIO *bio, const RSA *rsa, int indent) {
  bssl::UniquePtr<EVP_PKEY> pkey(EVP_PKEY_new());
  return pkey != nullptr &&
         EVP_PKEY_set1_RSA(pkey.get(), const_cast<RSA *>(rsa)) &&
         EVP_PKEY_print_private(bio, pkey.get(), indent, nullptr);
}
