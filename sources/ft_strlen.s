			global		_ft_strlen

			section		.text
;size_t		ft_strlen(const char *str);
_ft_strlen:	xor			rax, rax
			jmp			test

test:		cmp	byte	[rdi + rax], 0
			je			end_str
			inc			rax
			jmp			test

end_str		ret
