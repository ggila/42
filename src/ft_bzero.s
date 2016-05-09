section .text
	global _ft_bzero


_ft_bzero:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je .done

.again:
	cmp esi, 0
	jle .done
	mov [rdi], byte 0
	dec rsi
	inc rdi
	jmp .again

.done:
	pop rbp
	ret
