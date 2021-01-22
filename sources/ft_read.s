			global		_ft_read
			extern		___error

			section		.text
;ssize_t	ft_read(int fd, void *buf, size_t count);
_ft_read:	mov			rax, 0x2000003
			syscall
			jc			error
			ret

error:		mov			r8, rax
			call		___error
			mov			[rax], r8
			mov			rax, -1
			ret