#define BORINGSSL_PREFIX CCryptoBoringSSL
// This file is generated from a similarly-named Perl script in the BoringSSL
// source tree. Do not edit by hand.

#include <CCryptoBoringSSL_asm_base.h>

#if !defined(OPENSSL_NO_ASM) && defined(OPENSSL_X86_64) && defined(__ELF__)
.section	.rodata
.align	16


.Lbswap_mask:
.quad	0x08090a0b0c0d0e0f, 0x0001020304050607








.Lgfpoly:
.quad	1, 0xc200000000000000


.Lgfpoly_and_internal_carrybit:
.quad	1, 0xc200000000000001

.align	32

.Lctr_pattern:
.quad	0, 0
.quad	1, 0
.Linc_2blocks:
.quad	2, 0
.quad	2, 0

.text	
.globl	gcm_init_vpclmulqdq_avx2
.hidden gcm_init_vpclmulqdq_avx2
.type	gcm_init_vpclmulqdq_avx2,@function
.align	32
gcm_init_vpclmulqdq_avx2:
.cfi_startproc	

_CET_ENDBR





	vpshufd	$0x4e,(%rsi),%xmm3





	vpshufd	$0xd3,%xmm3,%xmm0
	vpsrad	$31,%xmm0,%xmm0
	vpaddq	%xmm3,%xmm3,%xmm3
	vpand	.Lgfpoly_and_internal_carrybit(%rip),%xmm0,%xmm0
	vpxor	%xmm0,%xmm3,%xmm3

	vbroadcasti128	.Lgfpoly(%rip),%ymm6


	vpclmulqdq	$0x00,%xmm3,%xmm3,%xmm0
	vpclmulqdq	$0x11,%xmm3,%xmm3,%xmm5
	vpclmulqdq	$0x01,%xmm0,%xmm6,%xmm1
	vpshufd	$0x4e,%xmm0,%xmm0
	vpxor	%xmm0,%xmm1,%xmm1
	vpclmulqdq	$0x01,%xmm1,%xmm6,%xmm0
	vpshufd	$0x4e,%xmm1,%xmm1
	vpxor	%xmm1,%xmm5,%xmm5
	vpxor	%xmm0,%xmm5,%xmm5



	vinserti128	$1,%xmm3,%ymm5,%ymm3
	vinserti128	$1,%xmm5,%ymm5,%ymm5


	vpclmulqdq	$0x00,%ymm5,%ymm3,%ymm0
	vpclmulqdq	$0x01,%ymm5,%ymm3,%ymm1
	vpclmulqdq	$0x10,%ymm5,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpclmulqdq	$0x01,%ymm0,%ymm6,%ymm2
	vpshufd	$0x4e,%ymm0,%ymm0
	vpxor	%ymm0,%ymm1,%ymm1
	vpxor	%ymm2,%ymm1,%ymm1
	vpclmulqdq	$0x11,%ymm5,%ymm3,%ymm4
	vpclmulqdq	$0x01,%ymm1,%ymm6,%ymm0
	vpshufd	$0x4e,%ymm1,%ymm1
	vpxor	%ymm1,%ymm4,%ymm4
	vpxor	%ymm0,%ymm4,%ymm4



	vmovdqu	%ymm3,96(%rdi)
	vmovdqu	%ymm4,64(%rdi)



	vpunpcklqdq	%ymm3,%ymm4,%ymm0
	vpunpckhqdq	%ymm3,%ymm4,%ymm1
	vpxor	%ymm1,%ymm0,%ymm0
	vmovdqu	%ymm0,128+32(%rdi)


	vpclmulqdq	$0x00,%ymm5,%ymm4,%ymm0
	vpclmulqdq	$0x01,%ymm5,%ymm4,%ymm1
	vpclmulqdq	$0x10,%ymm5,%ymm4,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpclmulqdq	$0x01,%ymm0,%ymm6,%ymm2
	vpshufd	$0x4e,%ymm0,%ymm0
	vpxor	%ymm0,%ymm1,%ymm1
	vpxor	%ymm2,%ymm1,%ymm1
	vpclmulqdq	$0x11,%ymm5,%ymm4,%ymm3
	vpclmulqdq	$0x01,%ymm1,%ymm6,%ymm0
	vpshufd	$0x4e,%ymm1,%ymm1
	vpxor	%ymm1,%ymm3,%ymm3
	vpxor	%ymm0,%ymm3,%ymm3

	vpclmulqdq	$0x00,%ymm5,%ymm3,%ymm0
	vpclmulqdq	$0x01,%ymm5,%ymm3,%ymm1
	vpclmulqdq	$0x10,%ymm5,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpclmulqdq	$0x01,%ymm0,%ymm6,%ymm2
	vpshufd	$0x4e,%ymm0,%ymm0
	vpxor	%ymm0,%ymm1,%ymm1
	vpxor	%ymm2,%ymm1,%ymm1
	vpclmulqdq	$0x11,%ymm5,%ymm3,%ymm4
	vpclmulqdq	$0x01,%ymm1,%ymm6,%ymm0
	vpshufd	$0x4e,%ymm1,%ymm1
	vpxor	%ymm1,%ymm4,%ymm4
	vpxor	%ymm0,%ymm4,%ymm4

	vmovdqu	%ymm3,32(%rdi)
	vmovdqu	%ymm4,0(%rdi)



	vpunpcklqdq	%ymm3,%ymm4,%ymm0
	vpunpckhqdq	%ymm3,%ymm4,%ymm1
	vpxor	%ymm1,%ymm0,%ymm0
	vmovdqu	%ymm0,128(%rdi)

	vzeroupper
	ret

.cfi_endproc	
.size	gcm_init_vpclmulqdq_avx2, . - gcm_init_vpclmulqdq_avx2
.globl	gcm_gmult_vpclmulqdq_avx2
.hidden gcm_gmult_vpclmulqdq_avx2
.type	gcm_gmult_vpclmulqdq_avx2,@function
.align	32
gcm_gmult_vpclmulqdq_avx2:
.cfi_startproc	

_CET_ENDBR



	vmovdqu	(%rdi),%xmm0
	vmovdqu	.Lbswap_mask(%rip),%xmm1
	vmovdqu	128-16(%rsi),%xmm2
	vmovdqu	.Lgfpoly(%rip),%xmm3
	vpshufb	%xmm1,%xmm0,%xmm0

	vpclmulqdq	$0x00,%xmm2,%xmm0,%xmm4
	vpclmulqdq	$0x01,%xmm2,%xmm0,%xmm5
	vpclmulqdq	$0x10,%xmm2,%xmm0,%xmm6
	vpxor	%xmm6,%xmm5,%xmm5
	vpclmulqdq	$0x01,%xmm4,%xmm3,%xmm6
	vpshufd	$0x4e,%xmm4,%xmm4
	vpxor	%xmm4,%xmm5,%xmm5
	vpxor	%xmm6,%xmm5,%xmm5
	vpclmulqdq	$0x11,%xmm2,%xmm0,%xmm0
	vpclmulqdq	$0x01,%xmm5,%xmm3,%xmm4
	vpshufd	$0x4e,%xmm5,%xmm5
	vpxor	%xmm5,%xmm0,%xmm0
	vpxor	%xmm4,%xmm0,%xmm0


	vpshufb	%xmm1,%xmm0,%xmm0
	vmovdqu	%xmm0,(%rdi)


	ret

.cfi_endproc	
.size	gcm_gmult_vpclmulqdq_avx2, . - gcm_gmult_vpclmulqdq_avx2
.globl	gcm_ghash_vpclmulqdq_avx2
.hidden gcm_ghash_vpclmulqdq_avx2
.type	gcm_ghash_vpclmulqdq_avx2,@function
.align	32
gcm_ghash_vpclmulqdq_avx2:
.cfi_startproc	

_CET_ENDBR






	vmovdqu	.Lbswap_mask(%rip),%xmm6
	vmovdqu	.Lgfpoly(%rip),%xmm7


	vmovdqu	(%rdi),%xmm5
	vpshufb	%xmm6,%xmm5,%xmm5


	cmpq	$32,%rcx
	jb	.Lghash_lastblock



	vinserti128	$1,%xmm6,%ymm6,%ymm6
	vinserti128	$1,%xmm7,%ymm7,%ymm7

	cmpq	$127,%rcx
	jbe	.Lghash_loop_1x


	vmovdqu	128(%rsi),%ymm8
	vmovdqu	128+32(%rsi),%ymm9
.Lghash_loop_4x:

	vmovdqu	0(%rdx),%ymm1
	vpshufb	%ymm6,%ymm1,%ymm1
	vmovdqu	0(%rsi),%ymm2
	vpxor	%ymm5,%ymm1,%ymm1
	vpclmulqdq	$0x00,%ymm2,%ymm1,%ymm3
	vpclmulqdq	$0x11,%ymm2,%ymm1,%ymm5
	vpunpckhqdq	%ymm1,%ymm1,%ymm0
	vpxor	%ymm1,%ymm0,%ymm0
	vpclmulqdq	$0x00,%ymm8,%ymm0,%ymm4

	vmovdqu	32(%rdx),%ymm1
	vpshufb	%ymm6,%ymm1,%ymm1
	vmovdqu	32(%rsi),%ymm2
	vpclmulqdq	$0x00,%ymm2,%ymm1,%ymm0
	vpxor	%ymm0,%ymm3,%ymm3
	vpclmulqdq	$0x11,%ymm2,%ymm1,%ymm0
	vpxor	%ymm0,%ymm5,%ymm5
	vpunpckhqdq	%ymm1,%ymm1,%ymm0
	vpxor	%ymm1,%ymm0,%ymm0
	vpclmulqdq	$0x10,%ymm8,%ymm0,%ymm0
	vpxor	%ymm0,%ymm4,%ymm4

	vmovdqu	64(%rdx),%ymm1
	vpshufb	%ymm6,%ymm1,%ymm1
	vmovdqu	64(%rsi),%ymm2
	vpclmulqdq	$0x00,%ymm2,%ymm1,%ymm0
	vpxor	%ymm0,%ymm3,%ymm3
	vpclmulqdq	$0x11,%ymm2,%ymm1,%ymm0
	vpxor	%ymm0,%ymm5,%ymm5
	vpunpckhqdq	%ymm1,%ymm1,%ymm0
	vpxor	%ymm1,%ymm0,%ymm0
	vpclmulqdq	$0x00,%ymm9,%ymm0,%ymm0
	vpxor	%ymm0,%ymm4,%ymm4


	vmovdqu	96(%rdx),%ymm1
	vpshufb	%ymm6,%ymm1,%ymm1
	vmovdqu	96(%rsi),%ymm2
	vpclmulqdq	$0x00,%ymm2,%ymm1,%ymm0
	vpxor	%ymm0,%ymm3,%ymm3
	vpclmulqdq	$0x11,%ymm2,%ymm1,%ymm0
	vpxor	%ymm0,%ymm5,%ymm5
	vpunpckhqdq	%ymm1,%ymm1,%ymm0
	vpxor	%ymm1,%ymm0,%ymm0
	vpclmulqdq	$0x10,%ymm9,%ymm0,%ymm0
	vpxor	%ymm0,%ymm4,%ymm4

	vpxor	%ymm3,%ymm4,%ymm4
	vpxor	%ymm5,%ymm4,%ymm4


	vbroadcasti128	.Lgfpoly(%rip),%ymm2
	vpclmulqdq	$0x01,%ymm3,%ymm2,%ymm0
	vpshufd	$0x4e,%ymm3,%ymm3
	vpxor	%ymm3,%ymm4,%ymm4
	vpxor	%ymm0,%ymm4,%ymm4

	vpclmulqdq	$0x01,%ymm4,%ymm2,%ymm0
	vpshufd	$0x4e,%ymm4,%ymm4
	vpxor	%ymm4,%ymm5,%ymm5
	vpxor	%ymm0,%ymm5,%ymm5
	vextracti128	$1,%ymm5,%xmm0
	vpxor	%xmm0,%xmm5,%xmm5

	subq	$-128,%rdx
	addq	$-128,%rcx
	cmpq	$127,%rcx
	ja	.Lghash_loop_4x


	cmpq	$32,%rcx
	jb	.Lghash_loop_1x_done
.Lghash_loop_1x:
	vmovdqu	(%rdx),%ymm0
	vpshufb	%ymm6,%ymm0,%ymm0
	vpxor	%ymm0,%ymm5,%ymm5
	vmovdqu	128-32(%rsi),%ymm0
	vpclmulqdq	$0x00,%ymm0,%ymm5,%ymm1
	vpclmulqdq	$0x01,%ymm0,%ymm5,%ymm2
	vpclmulqdq	$0x10,%ymm0,%ymm5,%ymm3
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x01,%ymm1,%ymm7,%ymm3
	vpshufd	$0x4e,%ymm1,%ymm1
	vpxor	%ymm1,%ymm2,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x11,%ymm0,%ymm5,%ymm5
	vpclmulqdq	$0x01,%ymm2,%ymm7,%ymm1
	vpshufd	$0x4e,%ymm2,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpxor	%ymm1,%ymm5,%ymm5

	vextracti128	$1,%ymm5,%xmm0
	vpxor	%xmm0,%xmm5,%xmm5
	addq	$32,%rdx
	subq	$32,%rcx
	cmpq	$32,%rcx
	jae	.Lghash_loop_1x
.Lghash_loop_1x_done:


.Lghash_lastblock:
	testq	%rcx,%rcx
	jz	.Lghash_done
	vmovdqu	(%rdx),%xmm0
	vpshufb	%xmm6,%xmm0,%xmm0
	vpxor	%xmm0,%xmm5,%xmm5
	vmovdqu	128-16(%rsi),%xmm0
	vpclmulqdq	$0x00,%xmm0,%xmm5,%xmm1
	vpclmulqdq	$0x01,%xmm0,%xmm5,%xmm2
	vpclmulqdq	$0x10,%xmm0,%xmm5,%xmm3
	vpxor	%xmm3,%xmm2,%xmm2
	vpclmulqdq	$0x01,%xmm1,%xmm7,%xmm3
	vpshufd	$0x4e,%xmm1,%xmm1
	vpxor	%xmm1,%xmm2,%xmm2
	vpxor	%xmm3,%xmm2,%xmm2
	vpclmulqdq	$0x11,%xmm0,%xmm5,%xmm5
	vpclmulqdq	$0x01,%xmm2,%xmm7,%xmm1
	vpshufd	$0x4e,%xmm2,%xmm2
	vpxor	%xmm2,%xmm5,%xmm5
	vpxor	%xmm1,%xmm5,%xmm5


.Lghash_done:

	vpshufb	%xmm6,%xmm5,%xmm5
	vmovdqu	%xmm5,(%rdi)

	vzeroupper
	ret

.cfi_endproc	
.size	gcm_ghash_vpclmulqdq_avx2, . - gcm_ghash_vpclmulqdq_avx2
.globl	aes_gcm_enc_update_vaes_avx2
.hidden aes_gcm_enc_update_vaes_avx2
.type	aes_gcm_enc_update_vaes_avx2,@function
.align	32
aes_gcm_enc_update_vaes_avx2:
.cfi_startproc	

_CET_ENDBR
	pushq	%r12
.cfi_adjust_cfa_offset	8
.cfi_offset	%r12,-16

	movq	16(%rsp),%r12
#ifdef BORINGSSL_DISPATCH_TEST
.extern	BORINGSSL_function_hit
.hidden BORINGSSL_function_hit
	movb	$1,BORINGSSL_function_hit+6(%rip)
#endif
	vbroadcasti128	.Lbswap_mask(%rip),%ymm0



	vmovdqu	(%r12),%xmm1
	vpshufb	%xmm0,%xmm1,%xmm1
	vbroadcasti128	(%r8),%ymm11
	vpshufb	%ymm0,%ymm11,%ymm11



	movl	240(%rcx),%r10d
	leal	-20(,%r10,4),%r10d




	leaq	96(%rcx,%r10,4),%r11
	vbroadcasti128	(%rcx),%ymm9
	vbroadcasti128	(%r11),%ymm10


	vpaddd	.Lctr_pattern(%rip),%ymm11,%ymm11



	cmpq	$127,%rdx
	jbe	.Lcrypt_loop_4x_done__func1

	vmovdqu	128(%r9),%ymm7
	vmovdqu	128+32(%r9),%ymm8



	vmovdqu	.Linc_2blocks(%rip),%ymm2
	vpshufb	%ymm0,%ymm11,%ymm12
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm13
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm14
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm15
	vpaddd	%ymm2,%ymm11,%ymm11


	vpxor	%ymm9,%ymm12,%ymm12
	vpxor	%ymm9,%ymm13,%ymm13
	vpxor	%ymm9,%ymm14,%ymm14
	vpxor	%ymm9,%ymm15,%ymm15

	leaq	16(%rcx),%rax
.Lvaesenc_loop_first_4_vecs__func1:
	vbroadcasti128	(%rax),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	addq	$16,%rax
	cmpq	%rax,%r11
	jne	.Lvaesenc_loop_first_4_vecs__func1
	vpxor	0(%rdi),%ymm10,%ymm2
	vpxor	32(%rdi),%ymm10,%ymm3
	vpxor	64(%rdi),%ymm10,%ymm5
	vpxor	96(%rdi),%ymm10,%ymm6
	vaesenclast	%ymm2,%ymm12,%ymm12
	vaesenclast	%ymm3,%ymm13,%ymm13
	vaesenclast	%ymm5,%ymm14,%ymm14
	vaesenclast	%ymm6,%ymm15,%ymm15
	vmovdqu	%ymm12,0(%rsi)
	vmovdqu	%ymm13,32(%rsi)
	vmovdqu	%ymm14,64(%rsi)
	vmovdqu	%ymm15,96(%rsi)

	subq	$-128,%rdi
	addq	$-128,%rdx
	cmpq	$127,%rdx
	jbe	.Lghash_last_ciphertext_4x__func1
.align	16
.Lcrypt_loop_4x__func1:




	vmovdqu	.Linc_2blocks(%rip),%ymm2
	vpshufb	%ymm0,%ymm11,%ymm12
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm13
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm14
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm15
	vpaddd	%ymm2,%ymm11,%ymm11


	vpxor	%ymm9,%ymm12,%ymm12
	vpxor	%ymm9,%ymm13,%ymm13
	vpxor	%ymm9,%ymm14,%ymm14
	vpxor	%ymm9,%ymm15,%ymm15

	cmpl	$24,%r10d
	jl	.Laes128__func1
	je	.Laes192__func1

	vbroadcasti128	-208(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vbroadcasti128	-192(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

.Laes192__func1:
	vbroadcasti128	-176(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vbroadcasti128	-160(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

.Laes128__func1:
	prefetcht0	512(%rdi)
	prefetcht0	512+64(%rdi)

	vmovdqu	0(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	0(%r9),%ymm4
	vpxor	%ymm1,%ymm3,%ymm3
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x00,%ymm7,%ymm2,%ymm6

	vbroadcasti128	-144(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vbroadcasti128	-128(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vmovdqu	32(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	32(%r9),%ymm4
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x10,%ymm7,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6

	vbroadcasti128	-112(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vmovdqu	64(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	64(%r9),%ymm4

	vbroadcasti128	-96(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1

	vbroadcasti128	-80(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x00,%ymm8,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6


	vmovdqu	96(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3

	vbroadcasti128	-64(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vmovdqu	96(%r9),%ymm4
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x10,%ymm8,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6

	vbroadcasti128	-48(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm1,%ymm6,%ymm6


	vbroadcasti128	.Lgfpoly(%rip),%ymm4
	vpclmulqdq	$0x01,%ymm5,%ymm4,%ymm2
	vpshufd	$0x4e,%ymm5,%ymm5
	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm2,%ymm6,%ymm6

	vbroadcasti128	-32(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vpclmulqdq	$0x01,%ymm6,%ymm4,%ymm2
	vpshufd	$0x4e,%ymm6,%ymm6
	vpxor	%ymm6,%ymm1,%ymm1
	vpxor	%ymm2,%ymm1,%ymm1

	vbroadcasti128	-16(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vextracti128	$1,%ymm1,%xmm2
	vpxor	%xmm2,%xmm1,%xmm1


	subq	$-128,%rsi
	vpxor	0(%rdi),%ymm10,%ymm2
	vpxor	32(%rdi),%ymm10,%ymm3
	vpxor	64(%rdi),%ymm10,%ymm5
	vpxor	96(%rdi),%ymm10,%ymm6
	vaesenclast	%ymm2,%ymm12,%ymm12
	vaesenclast	%ymm3,%ymm13,%ymm13
	vaesenclast	%ymm5,%ymm14,%ymm14
	vaesenclast	%ymm6,%ymm15,%ymm15
	vmovdqu	%ymm12,0(%rsi)
	vmovdqu	%ymm13,32(%rsi)
	vmovdqu	%ymm14,64(%rsi)
	vmovdqu	%ymm15,96(%rsi)

	subq	$-128,%rdi

	addq	$-128,%rdx
	cmpq	$127,%rdx
	ja	.Lcrypt_loop_4x__func1
.Lghash_last_ciphertext_4x__func1:

	vmovdqu	0(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	0(%r9),%ymm4
	vpxor	%ymm1,%ymm3,%ymm3
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x00,%ymm7,%ymm2,%ymm6

	vmovdqu	32(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	32(%r9),%ymm4
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x10,%ymm7,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6

	vmovdqu	64(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	64(%r9),%ymm4
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x00,%ymm8,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6


	vmovdqu	96(%rsi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	96(%r9),%ymm4
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x10,%ymm8,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6

	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm1,%ymm6,%ymm6


	vbroadcasti128	.Lgfpoly(%rip),%ymm4
	vpclmulqdq	$0x01,%ymm5,%ymm4,%ymm2
	vpshufd	$0x4e,%ymm5,%ymm5
	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm2,%ymm6,%ymm6

	vpclmulqdq	$0x01,%ymm6,%ymm4,%ymm2
	vpshufd	$0x4e,%ymm6,%ymm6
	vpxor	%ymm6,%ymm1,%ymm1
	vpxor	%ymm2,%ymm1,%ymm1
	vextracti128	$1,%ymm1,%xmm2
	vpxor	%xmm2,%xmm1,%xmm1

	subq	$-128,%rsi
.Lcrypt_loop_4x_done__func1:

	testq	%rdx,%rdx
	jz	.Ldone__func1





	leaq	128(%r9),%r8
	subq	%rdx,%r8


	vpxor	%xmm5,%xmm5,%xmm5
	vpxor	%xmm6,%xmm6,%xmm6
	vpxor	%xmm7,%xmm7,%xmm7

	cmpq	$64,%rdx
	jb	.Llessthan64bytes__func1


	vpshufb	%ymm0,%ymm11,%ymm12
	vpaddd	.Linc_2blocks(%rip),%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm13
	vpaddd	.Linc_2blocks(%rip),%ymm11,%ymm11
	vpxor	%ymm9,%ymm12,%ymm12
	vpxor	%ymm9,%ymm13,%ymm13
	leaq	16(%rcx),%rax
.Lvaesenc_loop_tail_1__func1:
	vbroadcasti128	(%rax),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	addq	$16,%rax
	cmpq	%rax,%r11
	jne	.Lvaesenc_loop_tail_1__func1
	vaesenclast	%ymm10,%ymm12,%ymm12
	vaesenclast	%ymm10,%ymm13,%ymm13


	vmovdqu	0(%rdi),%ymm2
	vmovdqu	32(%rdi),%ymm3
	vpxor	%ymm2,%ymm12,%ymm12
	vpxor	%ymm3,%ymm13,%ymm13
	vmovdqu	%ymm12,0(%rsi)
	vmovdqu	%ymm13,32(%rsi)


	vpshufb	%ymm0,%ymm12,%ymm12
	vpshufb	%ymm0,%ymm13,%ymm13
	vpxor	%ymm1,%ymm12,%ymm12
	vmovdqu	(%r8),%ymm2
	vmovdqu	32(%r8),%ymm3
	vpclmulqdq	$0x00,%ymm2,%ymm12,%ymm5
	vpclmulqdq	$0x01,%ymm2,%ymm12,%ymm6
	vpclmulqdq	$0x10,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%ymm2,%ymm12,%ymm7
	vpclmulqdq	$0x00,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm5,%ymm5
	vpclmulqdq	$0x01,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x10,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm7,%ymm7

	addq	$64,%r8
	addq	$64,%rdi
	addq	$64,%rsi
	subq	$64,%rdx
	jz	.Lreduce__func1

	vpxor	%xmm1,%xmm1,%xmm1


.Llessthan64bytes__func1:
	vpshufb	%ymm0,%ymm11,%ymm12
	vpaddd	.Linc_2blocks(%rip),%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm13
	vpxor	%ymm9,%ymm12,%ymm12
	vpxor	%ymm9,%ymm13,%ymm13
	leaq	16(%rcx),%rax
.Lvaesenc_loop_tail_2__func1:
	vbroadcasti128	(%rax),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	addq	$16,%rax
	cmpq	%rax,%r11
	jne	.Lvaesenc_loop_tail_2__func1
	vaesenclast	%ymm10,%ymm12,%ymm12
	vaesenclast	%ymm10,%ymm13,%ymm13




	cmpq	$32,%rdx
	jb	.Lxor_one_block__func1
	je	.Lxor_two_blocks__func1

.Lxor_three_blocks__func1:
	vmovdqu	0(%rdi),%ymm2
	vmovdqu	32(%rdi),%xmm3
	vpxor	%ymm2,%ymm12,%ymm12
	vpxor	%xmm3,%xmm13,%xmm13
	vmovdqu	%ymm12,0(%rsi)
	vmovdqu	%xmm13,32(%rsi)

	vpshufb	%ymm0,%ymm12,%ymm12
	vpshufb	%xmm0,%xmm13,%xmm13
	vpxor	%ymm1,%ymm12,%ymm12
	vmovdqu	(%r8),%ymm2
	vmovdqu	32(%r8),%xmm3
	vpclmulqdq	$0x00,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm5,%ymm5
	vpclmulqdq	$0x01,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x10,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm7,%ymm7
	jmp	.Lghash_mul_one_vec_unreduced__func1

.Lxor_two_blocks__func1:
	vmovdqu	(%rdi),%ymm2
	vpxor	%ymm2,%ymm12,%ymm12
	vmovdqu	%ymm12,(%rsi)
	vpshufb	%ymm0,%ymm12,%ymm12
	vpxor	%ymm1,%ymm12,%ymm12
	vmovdqu	(%r8),%ymm2
	jmp	.Lghash_mul_one_vec_unreduced__func1

.Lxor_one_block__func1:
	vmovdqu	(%rdi),%xmm2
	vpxor	%xmm2,%xmm12,%xmm12
	vmovdqu	%xmm12,(%rsi)
	vpshufb	%xmm0,%xmm12,%xmm12
	vpxor	%xmm1,%xmm12,%xmm12
	vmovdqu	(%r8),%xmm2

.Lghash_mul_one_vec_unreduced__func1:
	vpclmulqdq	$0x00,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm5,%ymm5
	vpclmulqdq	$0x01,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x10,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm7,%ymm7

.Lreduce__func1:

	vbroadcasti128	.Lgfpoly(%rip),%ymm2
	vpclmulqdq	$0x01,%ymm5,%ymm2,%ymm3
	vpshufd	$0x4e,%ymm5,%ymm5
	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm3,%ymm6,%ymm6
	vpclmulqdq	$0x01,%ymm6,%ymm2,%ymm3
	vpshufd	$0x4e,%ymm6,%ymm6
	vpxor	%ymm6,%ymm7,%ymm7
	vpxor	%ymm3,%ymm7,%ymm7
	vextracti128	$1,%ymm7,%xmm1
	vpxor	%xmm7,%xmm1,%xmm1

.Ldone__func1:

	vpshufb	%xmm0,%xmm1,%xmm1
	vmovdqu	%xmm1,(%r12)

	vzeroupper
	popq	%r12
.cfi_adjust_cfa_offset	-8
.cfi_restore	%r12
	ret

.cfi_endproc	
.size	aes_gcm_enc_update_vaes_avx2, . - aes_gcm_enc_update_vaes_avx2
.globl	aes_gcm_dec_update_vaes_avx2
.hidden aes_gcm_dec_update_vaes_avx2
.type	aes_gcm_dec_update_vaes_avx2,@function
.align	32
aes_gcm_dec_update_vaes_avx2:
.cfi_startproc	

_CET_ENDBR
	pushq	%r12
.cfi_adjust_cfa_offset	8
.cfi_offset	%r12,-16

	movq	16(%rsp),%r12
	vbroadcasti128	.Lbswap_mask(%rip),%ymm0



	vmovdqu	(%r12),%xmm1
	vpshufb	%xmm0,%xmm1,%xmm1
	vbroadcasti128	(%r8),%ymm11
	vpshufb	%ymm0,%ymm11,%ymm11



	movl	240(%rcx),%r10d
	leal	-20(,%r10,4),%r10d




	leaq	96(%rcx,%r10,4),%r11
	vbroadcasti128	(%rcx),%ymm9
	vbroadcasti128	(%r11),%ymm10


	vpaddd	.Lctr_pattern(%rip),%ymm11,%ymm11



	cmpq	$127,%rdx
	jbe	.Lcrypt_loop_4x_done__func2

	vmovdqu	128(%r9),%ymm7
	vmovdqu	128+32(%r9),%ymm8
.align	16
.Lcrypt_loop_4x__func2:




	vmovdqu	.Linc_2blocks(%rip),%ymm2
	vpshufb	%ymm0,%ymm11,%ymm12
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm13
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm14
	vpaddd	%ymm2,%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm15
	vpaddd	%ymm2,%ymm11,%ymm11


	vpxor	%ymm9,%ymm12,%ymm12
	vpxor	%ymm9,%ymm13,%ymm13
	vpxor	%ymm9,%ymm14,%ymm14
	vpxor	%ymm9,%ymm15,%ymm15

	cmpl	$24,%r10d
	jl	.Laes128__func2
	je	.Laes192__func2

	vbroadcasti128	-208(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vbroadcasti128	-192(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

.Laes192__func2:
	vbroadcasti128	-176(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vbroadcasti128	-160(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

.Laes128__func2:
	prefetcht0	512(%rdi)
	prefetcht0	512+64(%rdi)

	vmovdqu	0(%rdi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	0(%r9),%ymm4
	vpxor	%ymm1,%ymm3,%ymm3
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x00,%ymm7,%ymm2,%ymm6

	vbroadcasti128	-144(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vbroadcasti128	-128(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vmovdqu	32(%rdi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	32(%r9),%ymm4
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x10,%ymm7,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6

	vbroadcasti128	-112(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vmovdqu	64(%rdi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3
	vmovdqu	64(%r9),%ymm4

	vbroadcasti128	-96(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1

	vbroadcasti128	-80(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x00,%ymm8,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6


	vmovdqu	96(%rdi),%ymm3
	vpshufb	%ymm0,%ymm3,%ymm3

	vbroadcasti128	-64(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vmovdqu	96(%r9),%ymm4
	vpclmulqdq	$0x00,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm5,%ymm5
	vpclmulqdq	$0x11,%ymm4,%ymm3,%ymm2
	vpxor	%ymm2,%ymm1,%ymm1
	vpunpckhqdq	%ymm3,%ymm3,%ymm2
	vpxor	%ymm3,%ymm2,%ymm2
	vpclmulqdq	$0x10,%ymm8,%ymm2,%ymm2
	vpxor	%ymm2,%ymm6,%ymm6

	vbroadcasti128	-48(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm1,%ymm6,%ymm6


	vbroadcasti128	.Lgfpoly(%rip),%ymm4
	vpclmulqdq	$0x01,%ymm5,%ymm4,%ymm2
	vpshufd	$0x4e,%ymm5,%ymm5
	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm2,%ymm6,%ymm6

	vbroadcasti128	-32(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15


	vpclmulqdq	$0x01,%ymm6,%ymm4,%ymm2
	vpshufd	$0x4e,%ymm6,%ymm6
	vpxor	%ymm6,%ymm1,%ymm1
	vpxor	%ymm2,%ymm1,%ymm1

	vbroadcasti128	-16(%r11),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	vaesenc	%ymm2,%ymm14,%ymm14
	vaesenc	%ymm2,%ymm15,%ymm15

	vextracti128	$1,%ymm1,%xmm2
	vpxor	%xmm2,%xmm1,%xmm1



	vpxor	0(%rdi),%ymm10,%ymm2
	vpxor	32(%rdi),%ymm10,%ymm3
	vpxor	64(%rdi),%ymm10,%ymm5
	vpxor	96(%rdi),%ymm10,%ymm6
	vaesenclast	%ymm2,%ymm12,%ymm12
	vaesenclast	%ymm3,%ymm13,%ymm13
	vaesenclast	%ymm5,%ymm14,%ymm14
	vaesenclast	%ymm6,%ymm15,%ymm15
	vmovdqu	%ymm12,0(%rsi)
	vmovdqu	%ymm13,32(%rsi)
	vmovdqu	%ymm14,64(%rsi)
	vmovdqu	%ymm15,96(%rsi)

	subq	$-128,%rdi
	subq	$-128,%rsi
	addq	$-128,%rdx
	cmpq	$127,%rdx
	ja	.Lcrypt_loop_4x__func2
.Lcrypt_loop_4x_done__func2:

	testq	%rdx,%rdx
	jz	.Ldone__func2





	leaq	128(%r9),%r8
	subq	%rdx,%r8


	vpxor	%xmm5,%xmm5,%xmm5
	vpxor	%xmm6,%xmm6,%xmm6
	vpxor	%xmm7,%xmm7,%xmm7

	cmpq	$64,%rdx
	jb	.Llessthan64bytes__func2


	vpshufb	%ymm0,%ymm11,%ymm12
	vpaddd	.Linc_2blocks(%rip),%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm13
	vpaddd	.Linc_2blocks(%rip),%ymm11,%ymm11
	vpxor	%ymm9,%ymm12,%ymm12
	vpxor	%ymm9,%ymm13,%ymm13
	leaq	16(%rcx),%rax
.Lvaesenc_loop_tail_1__func2:
	vbroadcasti128	(%rax),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	addq	$16,%rax
	cmpq	%rax,%r11
	jne	.Lvaesenc_loop_tail_1__func2
	vaesenclast	%ymm10,%ymm12,%ymm12
	vaesenclast	%ymm10,%ymm13,%ymm13


	vmovdqu	0(%rdi),%ymm2
	vmovdqu	32(%rdi),%ymm3
	vpxor	%ymm2,%ymm12,%ymm12
	vpxor	%ymm3,%ymm13,%ymm13
	vmovdqu	%ymm12,0(%rsi)
	vmovdqu	%ymm13,32(%rsi)


	vpshufb	%ymm0,%ymm2,%ymm12
	vpshufb	%ymm0,%ymm3,%ymm13
	vpxor	%ymm1,%ymm12,%ymm12
	vmovdqu	(%r8),%ymm2
	vmovdqu	32(%r8),%ymm3
	vpclmulqdq	$0x00,%ymm2,%ymm12,%ymm5
	vpclmulqdq	$0x01,%ymm2,%ymm12,%ymm6
	vpclmulqdq	$0x10,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%ymm2,%ymm12,%ymm7
	vpclmulqdq	$0x00,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm5,%ymm5
	vpclmulqdq	$0x01,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x10,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%ymm3,%ymm13,%ymm4
	vpxor	%ymm4,%ymm7,%ymm7

	addq	$64,%r8
	addq	$64,%rdi
	addq	$64,%rsi
	subq	$64,%rdx
	jz	.Lreduce__func2

	vpxor	%xmm1,%xmm1,%xmm1


.Llessthan64bytes__func2:
	vpshufb	%ymm0,%ymm11,%ymm12
	vpaddd	.Linc_2blocks(%rip),%ymm11,%ymm11
	vpshufb	%ymm0,%ymm11,%ymm13
	vpxor	%ymm9,%ymm12,%ymm12
	vpxor	%ymm9,%ymm13,%ymm13
	leaq	16(%rcx),%rax
.Lvaesenc_loop_tail_2__func2:
	vbroadcasti128	(%rax),%ymm2
	vaesenc	%ymm2,%ymm12,%ymm12
	vaesenc	%ymm2,%ymm13,%ymm13
	addq	$16,%rax
	cmpq	%rax,%r11
	jne	.Lvaesenc_loop_tail_2__func2
	vaesenclast	%ymm10,%ymm12,%ymm12
	vaesenclast	%ymm10,%ymm13,%ymm13




	cmpq	$32,%rdx
	jb	.Lxor_one_block__func2
	je	.Lxor_two_blocks__func2

.Lxor_three_blocks__func2:
	vmovdqu	0(%rdi),%ymm2
	vmovdqu	32(%rdi),%xmm3
	vpxor	%ymm2,%ymm12,%ymm12
	vpxor	%xmm3,%xmm13,%xmm13
	vmovdqu	%ymm12,0(%rsi)
	vmovdqu	%xmm13,32(%rsi)

	vpshufb	%ymm0,%ymm2,%ymm12
	vpshufb	%xmm0,%xmm3,%xmm13
	vpxor	%ymm1,%ymm12,%ymm12
	vmovdqu	(%r8),%ymm2
	vmovdqu	32(%r8),%xmm3
	vpclmulqdq	$0x00,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm5,%ymm5
	vpclmulqdq	$0x01,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x10,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%xmm3,%xmm13,%xmm4
	vpxor	%ymm4,%ymm7,%ymm7
	jmp	.Lghash_mul_one_vec_unreduced__func2

.Lxor_two_blocks__func2:
	vmovdqu	(%rdi),%ymm2
	vpxor	%ymm2,%ymm12,%ymm12
	vmovdqu	%ymm12,(%rsi)
	vpshufb	%ymm0,%ymm2,%ymm12
	vpxor	%ymm1,%ymm12,%ymm12
	vmovdqu	(%r8),%ymm2
	jmp	.Lghash_mul_one_vec_unreduced__func2

.Lxor_one_block__func2:
	vmovdqu	(%rdi),%xmm2
	vpxor	%xmm2,%xmm12,%xmm12
	vmovdqu	%xmm12,(%rsi)
	vpshufb	%xmm0,%xmm2,%xmm12
	vpxor	%xmm1,%xmm12,%xmm12
	vmovdqu	(%r8),%xmm2

.Lghash_mul_one_vec_unreduced__func2:
	vpclmulqdq	$0x00,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm5,%ymm5
	vpclmulqdq	$0x01,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x10,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm6,%ymm6
	vpclmulqdq	$0x11,%ymm2,%ymm12,%ymm4
	vpxor	%ymm4,%ymm7,%ymm7

.Lreduce__func2:

	vbroadcasti128	.Lgfpoly(%rip),%ymm2
	vpclmulqdq	$0x01,%ymm5,%ymm2,%ymm3
	vpshufd	$0x4e,%ymm5,%ymm5
	vpxor	%ymm5,%ymm6,%ymm6
	vpxor	%ymm3,%ymm6,%ymm6
	vpclmulqdq	$0x01,%ymm6,%ymm2,%ymm3
	vpshufd	$0x4e,%ymm6,%ymm6
	vpxor	%ymm6,%ymm7,%ymm7
	vpxor	%ymm3,%ymm7,%ymm7
	vextracti128	$1,%ymm7,%xmm1
	vpxor	%xmm7,%xmm1,%xmm1

.Ldone__func2:

	vpshufb	%xmm0,%xmm1,%xmm1
	vmovdqu	%xmm1,(%r12)

	vzeroupper
	popq	%r12
.cfi_adjust_cfa_offset	-8
.cfi_restore	%r12
	ret

.cfi_endproc	
.size	aes_gcm_dec_update_vaes_avx2, . - aes_gcm_dec_update_vaes_avx2
#endif
#if defined(__linux__) && defined(__ELF__)
.section .note.GNU-stack,"",%progbits
#endif

