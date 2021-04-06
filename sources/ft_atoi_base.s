			global		_ft_atoi_base

			section		.text
;int ft_atoi_base(const char *str, const char *base);
_ft_atoi_base:	xor			rax, rax		;initialization to 0
				xor			r8, r8			;initialization to 0
				xor			r9, r9			;initialization to 0
				jmp			chk_base

chk_base:		cmp byte	[rdx + r8], 0	;end of charset
				jz			chk_base_sz
				cmp byte	[rdx + r8], 9	;horizontal tab
				jz			bad_charset
				cmp byte	[rdx + r8], 10	;new line
				jz			bad_charset
				cmp byte	[rdx + r8], 11	;vertical tab
				jz			bad_charset
				cmp byte	[rdx + r8], 12	;form feed
				jz			bad_charset
				cmp byte	[rdx + r8], 13	;carriage return
				jz			bad_charset
				cmp byte	[rdx + r8], 32	;space
				jz			bad_charset
				cmp byte	[rdx + r8], 43	;+
				jz			bad_charset
				cmp byte	[rdx + r8], 45	;-
				jz			bad_charset
				inc			r8
				jmp			chk_base

chk_base_sz:	cmp			r8, 2
				jl			bad_charset		;charset size 1 or less
				xor			r8, r8			;initialization to 0
				xor			r9, r9			;initialization to 0
				jmp			chk_dbls

chk_dbls:		cmp byte	[rdx + r8], 0	;end of charset
				jz			chk_end
				jmp			chk_dbls_2

chk_dbls_2:		cmp byte	[rdx + r9], 0	;end of charset
				jz			chk_dbls_3
				cmp byte	[rdx + r9], [rdx + r8]
				jz			bad_charset
				inc			r9
				jmp			chk_dbls_2

chk_dbls_3:		inc			r8
				xor			r9
				jmp			chk_dbls

chk_end:		cmp byte	[rcx + r8], 0	;end of string
				jz			end
				inc			r8
				xor			r9, r9
				jmp			find_idx

find_idx:		cmp byte	[rdx + r9], 0	;not found in charset
				je			bad_charset
				cmp byte	[rcx + r8], [rdx + r9]	;character found in charset
				je			found
				inc 		r9
				jmp			find_idx

found:			mul			, rax
				add			r9, rax
				inc			r8
				jmp			chk_end

bad_charset:	xor			rax, rax
				ret
// ITS CHAR NOT INTS
// TAKE CARE OF 0 IN BASE
end:			ret