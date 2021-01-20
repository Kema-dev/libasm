/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:16:26 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 18:00:38 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	struct_init(t_params *param)
{
	param->strok = "\033[0;32mok!\033[0;37m";
	param->strfail = "\033[0;31mfail!\033[0;37m";
	param->errok = "\033[0;32merrno ok!\033[0;37m";
	param->errfail = "\033[0;31merrno fail!\033[0;37m";
	if (!(param->str_o = calloc(400, sizeof(char))))
		return (free_exit(param));
	if (!(param->str_u = calloc(400, sizeof(char))))
		return (free_exit(param));
	param->fd = 0;
	param->ret_o = 0;
	param->ret_u = 0;
	param->err_o = 0;
	param->err_u = 0;
	param->error_occured = 0;
	return (0);
}
