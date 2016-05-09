section .text
	global _ft_strcat


_ft_strcat:
	push rbp
	mov rbp, rsp
	mov rax, rdi

.check:
	cmp rdi, 0
	je .done
	cmp rsi, 0
	je .done

.skip:
	cmp [rdi], byte 0
	je .copy
	inc rdi
	jmp .skip

.copy:
	cmp [rsi], byte 0
	je .done
	mov r10b, [rsi]
	mov [rdi], r10b
	inc rsi
	inc rdi
	jmp .conclude

.conclude:
	mov [rdi], byte 0

.done:
	pop rbp
	ret
