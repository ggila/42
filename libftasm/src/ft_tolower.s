section .text
	global _ft_tolower


_ft_tolower:
	push rbp
	mov rbp, rsp

.checkmin:
	cmp rdi, 65
	jl .ko

.checkmax:
	cmp rdi, 90
	jg .ko

.ok:
	add rdi, 32
	mov rax, rdi
	pop rbp
	ret

.ko:
	mov rax, rdi
	pop rbp
	ret
