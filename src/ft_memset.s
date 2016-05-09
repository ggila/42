section .text
	global _ft_memset


_ft_memset:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je .done
	mov r8, rdi

.set:
	mov rcx, rdx
	mov rax, rsi
	rep stosb
	mov rax, r8

.done:
	leave
	ret
