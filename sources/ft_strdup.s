			global		ft_strdup
			extern 		ft_strlen, ft_strcpy, malloc

			section		.text
;char		*ft_strdup(const char *s);
ft_strdup:	call		ft_strlen
			add			rax, 1
			push		rdi
			mov			rdi, rax
			call		malloc
			pop			rcx
			mov			rdi, rax
			mov			rsi, rcx
			call		ft_strcpy
			ret