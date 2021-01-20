/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:46:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 15:13:53 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	test_strcpy(t_params *param)
{
	ssize_t	i;

	i = -1;
	while (param->args1[++i])
	{
		printf("Test with \"%s\" : ", param->args1[i]);
		param->str_o = strcpy(param->args1[i]);
		param->err_o = errno;
		param->str_u = ft_strcpy(param->args1[i]);
		param->err_u = errno;
		if (strcmp(param->str_o, param->str_u) == 0)
			printf("%s ", param->strok);
		else
			printf("%s you returned %s, expected %s", param->strfail, param->str_u, param->str_o);
		if (param->err_o == param->err_u)
			printf("%s\n", param->errok);
		else
			printf("%s your errno code is (%d) %s, expected (%d) %s\n", param->errfail, param->err_u, strerror(param->err_u), param->err_o, strerror(param->err_o));
	}
	return (0);
}
