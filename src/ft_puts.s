section .bss
	nl: resb 1

section .data
	nullstr: db "(null)"

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
	sub rsp, 16

.begin:
	cmp rdi, 0
	je .null
	call _ft_strlen
	mov rdx, rax
	mov rsi, rdi
	jmp .write

.null:
	mov rdx, 6
	lea rsi, [rel nullstr]
	jmp .write

.write:
	mov rdi, 1
	mov rax, 0x2000004
	syscall
	jmp .endl

.endl:
	mov rdx, 1
	lea rsi, [rel nl]
	mov [rsi], byte 10
	mov rax, 0x2000004
	syscall
	mov rax, 10
	jmp .done

.done:
	leave
	ret
