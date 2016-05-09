section .text
	global _ft_strdup
	extern _ft_memcpy
	extern _ft_strlen
	extern _malloc


_ft_strdup:
	push rbp
	mov rbp, rsp
	sub rsp, 16

.checkval:
	cmp rdi, 0
	jl .done

.getlen:
	call _ft_strlen
	inc rax

.alloc:
	push rdi
	mov rdi, rax
	push rax
	call _malloc
	cmp rax, 0
	jle .done

.copy:
	mov rdi, rax
	pop rdx
	pop rsi
	call _ft_memcpy

.done:
	leave
	ret
