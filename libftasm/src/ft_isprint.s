section .text
	global _ft_isprint


_ft_isprint:
	push rbp
	mov rbp, rsp

.checkmin:
	cmp rdi, 32
	jl .ko

.checkmax:
	cmp rdi, 126
	jg .ko

.ok:
	mov rax, 1
	pop rbp
	ret

.ko:
	mov rax, 0
	pop rbp
	ret
