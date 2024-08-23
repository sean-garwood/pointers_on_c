	.file	"runtime.c"
	.text
	.globl	static_variable
	.data
	.align 4
	.type	static_variable, @object
	.size	static_variable, 4
static_variable:
	.long	5
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.cfi_startproc;									 start the frame
	endbr64; 										 x86_64 specific

	; push the base frame pointer onto the stack
	pushq	%rbp

	; define the current frame pointer offset
	.cfi_def_cfa_offset 16

	; make room for the current frame pointer register
	.cfi_offset 6, -16

	; set the base frame pointer to the current stack pointer
	movq	%rsp, %rbp

	; define the current frame pointer register
	.cfi_def_cfa_register 6

	; push the caller-owned registers onto stack
	; 		this is in reverse arg order, descending from 3 to 1st arg of callee
	;       LIFO

	pushq	%r13 ; third arg in call to func_ret_int, i10
	pushq	%r12 ; second, i1
	pushq	%rbx ; first, literal 10

	; NOTE: The book shows all the declarations of the variables in the .s file.
	; It looks like the compiler is able to optimize the code (during
	; preprocessing?) to  make it more efficient.



	; allocate space for local variables
	;     sizeof(pointer) * 3 = 24 bytes
	;
	; move the stack pointer to allocate space for the local variables by
	; subtracting 24 from the stack pointer

	subq	$24, %rsp

	; define the current frame pointer offsets for the local variables
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40

	; store values in the caller-owned registers
	;     these are 32-bit subregisters due to data size

	movl	$1, %r12d ; i1
	movl	$10, %r13d; i10
	movl	$110, %ebx; c1
	movl	$1, a_very_long_name_to_see_how_long_they_can_be(%rip); local

	; move/pass data from caller-owned to callee-owned

	movl	%r13d, %edx;		  third arg
	movl	%r12d, %esi;          second arg
	movl	$10, %edi; 		  	  first arg

	; call the function `func_ret_int`. flow jumps to a new stack frame in the
	; function.

	movl	$0, %eax ; 			 init return register to zero
	call	func_ret_int

	; call the function `func_ret_double`
	movl	$0, %eax; 				 null eax
	call	func_ret_double
	movq	%xmm0, %rax
	movq	%rax, -40(%rbp)
	movq	%rbx, %rdi
	movl	$0, %eax
	call	func_ret_char_ptr
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.globl	func_ret_int
	.type	func_ret_int, @function
func_ret_int:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp ; push base pointer onto stack
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16

	; move the stack pointer to the base pointer
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6

	; store the arguments in the local variables

	movl	%edi, -20(%rbp) ; first arg
	movl	%esi, -24(%rbp) ; second arg
	movl	-24(%rbp), %eax ; move memory from offset rbp - 24 to return reg
	subl	$6, %eax ; 		  subtract 6 from the return reg
	movl	%eax, -4(%rbp) ;  move the return reg to offset rbp - 4
	movl	-20(%rbp), %ecx
	movl	-24(%rbp), %eax
	addl	%ecx, %eax
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func_ret_int, .-func_ret_int
	.globl	func_ret_double
	.type	func_ret_double, @function
func_ret_double:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	.LC0(%rip), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	func_ret_double, .-func_ret_double
	.globl	func_ret_char_ptr
	.type	func_ret_char_ptr, @function
func_ret_char_ptr:
.LFB3:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$1, %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	func_ret_char_ptr, .-func_ret_char_ptr
	.section	.rodata
	.align 8
.LC0:
	.long	1374389535
	.long	1074339512
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
