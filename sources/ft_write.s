			global		_ft_write

			section		.text
;ssize_t	ft_write(int fd, const void *buf, size_t count);
_ft_write:	push		r8
			mov			rax, 0x2000004
			syscall
			jc			error
			jmp			stop

error:		mov			rax, -1
			ret

stop:		pop 		rax
			ret