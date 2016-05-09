section .text
	global _ft_isascii


_ft_isascii:
	push rbp
	mov rbp, rsp
	cmp rdi, 127
	jg .ko
	mov rax, 1
	jmp .done

.ko:
	mov rax, 0
	jmp .done

.done:
	pop rbp
	ret
