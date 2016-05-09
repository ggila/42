section .text
	global _ft_toupper


_ft_toupper:
	push rbp
	mov rbp, rsp

.checkmin:
	cmp rdi, 97
	jl .ko

.checkmax:
	cmp rdi, 122
	jg .ko

.ok:
	sub rdi, 32
	mov rax, rdi
	pop rbp
	ret

.ko:
	mov rax, rdi
	pop rbp
	ret
