	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	_store(%rip), %rdi
	addq	$8, %rdi
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movq	%rdx, %rsi
	leaq	_fn_store(%rip), %r8
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	movq	%r8, %rdx
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	callq	_pthread_create
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jne	LBB0_8
## %bb.1:
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	$0, -8(%rbp)
	movl	%eax, -32(%rbp)         ## 4-byte Spill
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -8(%rbp)
	jge	LBB0_7
## %bb.3:                               ##   in Loop: Header=BB0_2 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	leaq	_store(%rip), %rcx
	addq	$16, %rcx
	movslq	-8(%rbp), %rdx
	shlq	$3, %rdx
	addq	%rdx, %rcx
	movslq	-8(%rbp), %rdx
	movq	%rcx, %rdi
	leaq	_fn_clients(%rip), %rcx
	movq	%rdx, -40(%rbp)         ## 8-byte Spill
	movq	%rcx, %rdx
	movq	-40(%rbp), %rcx         ## 8-byte Reload
	callq	_pthread_create
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	je	LBB0_5
## %bb.4:                               ##   in Loop: Header=BB0_2 Depth=1
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movl	-12(%rbp), %ecx
	movq	%rdi, -48(%rbp)         ## 8-byte Spill
	movl	%ecx, %edi
	callq	_strerror
	movq	-48(%rbp), %rdi         ## 8-byte Reload
	leaq	L_.str.2(%rip), %rsi
	movq	%rax, %rdx
	movb	$0, %al
	callq	_fprintf
	movl	%eax, -52(%rbp)         ## 4-byte Spill
LBB0_5:                                 ##   in Loop: Header=BB0_2 Depth=1
	jmp	LBB0_6
LBB0_6:                                 ##   in Loop: Header=BB0_2 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_2
LBB0_7:
	jmp	LBB0_9
LBB0_8:
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	movl	-12(%rbp), %ecx
	movq	%rdi, -64(%rbp)         ## 8-byte Spill
	movl	%ecx, %edi
	callq	_strerror
	movq	-64(%rbp), %rdi         ## 8-byte Reload
	leaq	L_.str.2(%rip), %rsi
	movq	%rax, %rdx
	movb	$0, %al
	callq	_fprintf
	movl	%eax, -68(%rbp)         ## 4-byte Spill
LBB0_9:
	movl	$0, -8(%rbp)
	movl	$0, -8(%rbp)
LBB0_10:                                ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -8(%rbp)
	jge	LBB0_13
## %bb.11:                              ##   in Loop: Header=BB0_10 Depth=1
	xorl	%eax, %eax
	movl	%eax, %esi
	movslq	-8(%rbp), %rcx
	leaq	_store(%rip), %rdx
	movq	16(%rdx,%rcx,8), %rdi
	callq	_pthread_join
	movl	%eax, -72(%rbp)         ## 4-byte Spill
## %bb.12:                              ##   in Loop: Header=BB0_10 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_10
LBB0_13:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	_store+8(%rip), %rdi
	callq	_pthread_join
	xorl	%ecx, %ecx
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function fn_store
_fn_store:                              ## @fn_store
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, _store(%rip)
	jg	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	$20, _store(%rip)
	movl	_store(%rip), %esi
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
LBB1_3:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_1
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function fn_clients
_fn_clients:                            ## @fn_clients
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movl	%edi, %eax
	movl	%eax, -20(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	$6, %edi
	callq	_get_random
	movl	%eax, -24(%rbp)
	movl	$3, %edi
	callq	_get_random
	movl	%eax, %edi
	callq	_sleep
	movl	_store(%rip), %edi
	cmpl	-24(%rbp), %edi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jl	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movl	_store(%rip), %eax
	subl	-24(%rbp), %eax
	movl	%eax, _store(%rip)
	movl	-20(%rbp), %esi
	movl	-24(%rbp), %edx
	movl	_store(%rip), %ecx
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -32(%rbp)         ## 4-byte Spill
LBB2_3:                                 ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_1
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function get_random
LCPI3_0:
	.quad	4746794007248502784     ## double 2147483648
	.section	__TEXT,__text,regular,pure_instructions
	.p2align	4, 0x90
_get_random:                            ## @get_random
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edi
	cvtsi2sdl	%edi, %xmm0
	movsd	%xmm0, -24(%rbp)        ## 8-byte Spill
	callq	_rand
	movsd	LCPI3_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	cvtsi2sdl	%eax, %xmm1
	movsd	-24(%rbp), %xmm2        ## 8-byte Reload
                                        ## xmm2 = mem[0],zero
	mulsd	%xmm1, %xmm2
	movsd	%xmm2, -16(%rbp)
	movsd	-16(%rbp), %xmm1        ## xmm1 = mem[0],zero
	divsd	%xmm0, %xmm1
	movsd	%xmm1, -16(%rbp)
	cvttsd2si	-16(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Creation du thread du magasin !\n"

	.section	__DATA,__data
	.p2align	3               ## @store
_store:
	.long	20                      ## 0x14
	.space	4
	.quad	0
	.space	40

	.section	__TEXT,__cstring,cstring_literals
L_.str.1:                               ## @.str.1
	.asciz	"Creation des threads clients !\n"

L_.str.2:                               ## @.str.2
	.asciz	"%s"

L_.str.3:                               ## @.str.3
	.asciz	"Remplissage du stock de %d articles !\n"

L_.str.4:                               ## @.str.4
	.asciz	"Client %d prend %d du stock, reste %d en stock !\n"


.subsections_via_symbols
