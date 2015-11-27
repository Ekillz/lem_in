	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_ft_strdup
	.align	4, 0x90
_ft_strdup:                             ## @ft_strdup
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB0_2
## BB#1:
	movq	$0, -8(%rbp)
	jmp	LBB0_8
LBB0_2:
	movq	-16(%rbp), %rdi
	callq	_ft_strlen
	movl	%eax, %ecx
	movl	%ecx, -20(%rbp)
	movl	-20(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rax
	shlq	$0, %rax
	movq	%rax, %rdi
	callq	_malloc
	movq	%rax, -32(%rbp)
	cmpq	$0, -32(%rbp)
	jne	LBB0_4
## BB#3:
	movq	$0, -8(%rbp)
	jmp	LBB0_8
LBB0_4:
	movl	$0, -24(%rbp)
LBB0_5:                                 ## =>This Inner Loop Header: Depth=1
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	LBB0_7
## BB#6:                                ##   in Loop: Header=BB0_5 Depth=1
	movslq	-24(%rbp), %rax
	movq	-16(%rbp), %rcx
	movb	(%rcx,%rax), %dl
	movslq	-24(%rbp), %rax
	movq	-32(%rbp), %rcx
	movb	%dl, (%rcx,%rax)
	movl	-24(%rbp), %esi
	addl	$1, %esi
	movl	%esi, -24(%rbp)
	jmp	LBB0_5
LBB0_7:
	movslq	-24(%rbp), %rax
	movq	-32(%rbp), %rcx
	movb	$0, (%rcx,%rax)
	movq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB0_8:
	movq	-8(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
