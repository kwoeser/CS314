	.file	"3-2.c"
	.text
	.globl	f
	.type	f, @function
f:
.LFB22:
	.cfi_startproc
	subq	%rsi, %rdx
	imulq	%rdx, %rdi
	salq	$63, %rdx
	sarq	$63, %rdx
	movq	%rdi, %rax
	orq	%rdx, %rax
	ret
	.cfi_endproc
.LFE22:
	.size	f, .-f
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"f(1, 2, 4): %d\n"
.LC1:
	.string	"f(3, 5, 7): %d\n"
.LC2:
	.string	"f(10, 20, 40): %d\n"
.LC3:
	.string	"f(30, 50, 70): %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$4, %edx
	movl	$2, %esi
	movl	$1, %edi
	call	f
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$7, %edx
	movl	$5, %esi
	movl	$3, %edi
	call	f
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$40, %edx
	movl	$20, %esi
	movl	$10, %edi
	call	f
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$70, %edx
	movl	$50, %esi
	movl	$30, %edi
	call	f
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
