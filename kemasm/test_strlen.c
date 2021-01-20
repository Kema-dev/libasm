/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:15:21 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 14:46:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	test_strlen(t_params *param)
{
	ssize_t	i;

	i = -1;
	while (param->args1[++i])
	{
		printf("Test with \"%s\" : ", param->args1[i]);
		param->ret_o = strlen(param->args1[i]);
		param->err_o = errno;
		param->ret_u = ft_strlen(param->args1[i]);
		param->err_u = errno;
		if (param->ret_o == param->ret_u)
			printf("%s ", param->strok);
		else
			printf("%s you returned %d, expected %d", param->strfail, param->ret_u, param->ret_o);
		if (param->err_o == param->err_u)
			printf("%s\n", param->errok);
		else
			printf("%s your errno code is (%d) %s, expected (%d) %s\n", param->errfail, param->err_u, strerror(param->err_u), param->err_o, strerror(param->err_o));
	}
	return (0);
}
