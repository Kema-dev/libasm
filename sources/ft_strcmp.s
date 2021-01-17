			global		ft_strcmp

			section		.text
ft_strcmp:	xor 		rax, rax
			xor			rcx, rcx
			jmp			loop

loop:		mov byte	dl, [rsi + rcx]
			cmp byte	[rdi + rcx], dl
			jne			end_loop
			inc			rcx
			jmp			loop

end_loop:	mov			rax, [rdi + rcx]
			sub			rax, [rsi + rcx]
			ret