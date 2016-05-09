section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit


_ft_isalnum:
	push rbp
	mov rbp, rsp
	call _ft_isalpha
	mov r9, rax
	call _ft_isdigit
	add rax, r9
	pop rbp
	ret
