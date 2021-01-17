			global		_ft_read

			section		.text
;ssize_t	ft_read(int fd, void *buf, size_t count);
_ft_read:	mov			rax, 0x2000003
			syscall
			jc			error
			jmp			stop

error:		mov			rax, -1
			ret

stop:		ret