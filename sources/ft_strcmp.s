			global		_ft_strcmp

			section		.text
;int		ft_strcmp(const char *s1, const char *s2);
_ft_strcmp:	xor			rax, rax
			jmp			test

test:
			mov			cl, BYTE [rdi]
			mov			dl, BYTE [rsi]
			cmp			cl, 0
			je			stop
			cmp			dl, 0
			je			stop
			cmp			cl, dl
			jne			stop
			inc			rdi
			inc			rsi
			jmp			test

stop:
			movzx		rax, cl
    		movzx		rbx, dl
   			sub			rax, rbx
			ret