section .text
	global _ft_strlen


_ft_strlen:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je .done

.begin:
	mov rax, 0
	mov r8, rdi
	mov r9, rdi
	mov rcx, -1
	repne scasb
	sub rdi, r8
	mov rax, rdi
	dec rax
	mov rdi, r9
	jmp .done

.done:
	pop rbp
	ret
