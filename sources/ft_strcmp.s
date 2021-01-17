			global		_ft_strcmp

			section		.text
;int		ft_strcmp(const char *s1, const char *s2);
_ft_strcmp:	xor 		rax, rax
			xor			rcx, rcx
			cmp			rsi, 0
			je			zero
			cmp			rdi, 0
			je			zero
			jmp			loop

loop:		mov byte	dl, [rsi + rcx]
			cmp byte	[rdi + rcx], dl
			jne			end_loop
			inc			rcx
			jmp			loop

end_loop:	mov			rax, [rdi + rcx]
			sub			rax, [rsi + rcx]
			ret

zero:		mov			rax, 0
			ret