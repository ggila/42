section .text
	global _ft_memcpy


_ft_memcpy:
	push rbp
	mov rbp, rsp

.checkval:
	cmp rdi, 0
	je .done
	cmp rsi, 0
	je .done

.save:
	mov r8, rdi

.copy:
	mov rcx, rdx
	repnz movsb

.restore:
	mov rax, r8

.done:
	leave
	ret
