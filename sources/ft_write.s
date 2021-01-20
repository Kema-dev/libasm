			global		_ft_write

			section		.text
;ssize_t	ft_write(int fd, const void *buf, size_t count);
_ft_write:	mov			r8, rdx
			mov			rax, 0x2000004
			syscall
			jnc			stop
			jmp			error

error:		mov			rax, -1
			ret

stop:		mov 		rax, r8
			ret