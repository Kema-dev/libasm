/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:16:26 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 13:43:11 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	struct_init(t_params param)
{
	param->strok = "\033[0;32mok!\033[0;37m";
	param->strfail = "\033[0;31mfail!\033[0;37m";
	param->errok = "\033[0;32merrno ok!\033[0;37m";
	param->errfail = "\033[0;31merrno fail!\033[0;37m";
	if (!(param->buf1 = calloc(400, sizeof(char))))
		return (-1);
	if (!(param->buf2 = calloc(400, sizeof(char))))
	{
		free(param->buf1);
		return (-1);
	}
	param->fd = 0;
	param->ret1 = 0;
	param->ret2 = 0;
	param->err1 = 0;
	param->err2 = 0;
	return (0);
}
