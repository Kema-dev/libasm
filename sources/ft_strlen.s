			global	_start

			section	.text
_ft_strlen:		xor		rax, rax
	_loop:		cmp		byte [rdi + rax], 0
				jz		_res
				inc		rax
				jmp		_loop

	_res:		ret