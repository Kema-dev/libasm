			global		_ft_strcmp

			section		.text
;int		ft_strcmp(const char *s1, const char *s2);
_ft_strcmp:	mov			al, BYTE [rdi]
			mov			bl, BYTE [rsi]
			cmp			al, 0
			je			zero
			cmp			bl, 0
			je			zero
			jmp			loop

loop:		mov			al, BYTE [rdi + rcx]
			mov			bl, BYTE [rsi + rcx]
			cmp byte	al, bl
			jne			end_loop
			inc			rcx
			jmp			loop

end_loop:	mov			rax, [rdi + rcx]
			sub			rax, [rsi + rcx]
			ret

zero:		mov			rax, 0
			ret