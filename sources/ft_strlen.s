			global		ft_strlen

			section		.text
ft_strlen:	xor			rax, rax
			jmp			test

test:		cmp	byte	[rdi + rax], 0
			jne			increment
			ret

increment	inc			rax
			jmp			test