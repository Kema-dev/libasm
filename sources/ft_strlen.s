			global		ft_strlen

			section		.text
ft_strlen:	xor			rax, rax
			jmp			test

test:		cmp	byte	[rdi + rax], 0
			je			end_str
			inc			rax
			jmp			test

end_str		ret