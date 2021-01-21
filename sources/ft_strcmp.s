
			global		_ft_strcmp

			section		.text
;int		ft_strcmp(const char *s1, const char *s2);
_ft_strcmp:	xor			rax, rax
			jmp			test

test:		movzx		r8, BYTE [rdi]
			movzx		r9, BYTE [rsi]
			mov			r10, r8
			or			r10, r9
			jz			end_equal
			cmp			r8, r9
			jne			end
			inc			rdi
			inc			rsi
			jmp			test

end_equal:	ret

end:		sub			r8, r9
			jl			less
			mov			rax, 1
			ret

less:		mov			rax, -1
			ret