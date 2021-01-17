			global		_ft_strdup
			extern 		_ft_strlen, _ft_strcpy, _malloc

			section		.text
;char		*ft_strdup(const char *s);
_ft_strdup:	call		_ft_strlen
			add			rax, 1
			push		rdi
			mov			rdi, rax
			call		_malloc
			pop			rcx
			mov			rdi, rax
			mov			rsi, rcx
			call		_ft_strcpy
			ret