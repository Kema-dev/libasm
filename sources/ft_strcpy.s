			global		_ft_strcpy

			section		.text
;char		*ft_strcpy(char *dst, const char *src);
_ft_strcpy:	xor 		rcx, rcx
			jmp			test

test:		cmp	byte	[rsi + rcx], 0
			je			end_str
			mov byte	dl, [rsi + rcx]
			mov byte	[rdi + rcx], dl
			inc			rcx
			jmp			test

end_str:	mov byte	[rdi + rcx], 0
			mov			rax, rdi
			ret