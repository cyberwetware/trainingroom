	.file	"Vector.cpp"
	.section	.text._ZN6VectorC2Ei,"axG",@progbits,_ZN6VectorC5Ei,comdat
	.align 2
	.weak	_ZN6VectorC2Ei
	.type	_ZN6VectorC2Ei, @function
_ZN6VectorC2Ei:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	cltq
	movabsq	$1143914305352105984, %rdx
	cmpq	%rdx, %rax
	ja	.L2
	salq	$3, %rax
	jmp	.L4
.L2:
	call	__cxa_throw_bad_array_new_length
.L4:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, 8(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN6VectorC2Ei, .-_ZN6VectorC2Ei
	.weak	_ZN6VectorC1Ei
	.set	_ZN6VectorC1Ei,_ZN6VectorC2Ei
	.globl	v
	.bss
	.align 16
	.type	v, @object
	.size	v, 16
v:
	.zero	16
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L7
	cmpl	$65535, -8(%rbp)
	jne	.L7
	movl	$6, %esi
	movl	$v, %edi
	call	_ZN6VectorC1Ei
.L7:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_v, @function
_GLOBAL__sub_I_v:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_GLOBAL__sub_I_v, .-_GLOBAL__sub_I_v
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_v
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
