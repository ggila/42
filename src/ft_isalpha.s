section .text
	global _ft_isalpha


_ft_isalpha:
	push rbp
	mov rbp, rsp

.checkminmin:
	cmp rdi, 65
	jl .ko

.checkmaxmax:
	cmp rdi, 122
	jg .ko

.checkminmax:
	cmp rdi, 90
	jg .checkmaxmin
	jmp .ok

.checkmaxmin:
	cmp rdi, 97
	jl .ko
	jmp .ok

.ko:
	mov rax, 0
	leave
	ret

.ok:
	mov rax, 1
	leave
	ret
