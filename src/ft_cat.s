section .bss
	buf: resb 256

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp
	lea rsi, [rel buf]
	mov r9, rdi

.read:
	mov rdi, r9
	mov rdx, 256
	mov rax, 0x2000003
	syscall
	jc .done
	cmp rax, 0
	je .done
	jmp .write

.write:
	mov rdi, 1
	mov rdx, rax
	mov rax, 0x2000004
	syscall
	jmp .read

.done:
	leave
	ret
