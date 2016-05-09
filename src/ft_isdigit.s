section .text
	global _ft_isdigit


_ft_isdigit:
	push rbp
	mov rbp, rsp

.checkmin:
	cmp rdi, 48
	jl .ko

.checkmax:
	cmp rdi, 57
	jg .ko

.ok:
	mov rax, 1
	pop rbp
	ret

.ko:
	mov rax, 0
	pop rbp
	ret
