/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:50:44 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/21 11:04:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	test_strcmp(t_params *param)
{
	ssize_t	i;
	char	*args2[11] = {"", "", "1", "", "1", "1", "12345", "12345", "12340", "12345", ""};

	i = -1;
	printf("\n\nTesting strcmp:\n\n");
	while (++i < 10)
	{
		printf("Test with \"%s\" and \"%s\" : ", args2[i], args2[i + 1]);
		param->ret_o = strcmp(args2[i], args2[i + 1]);
		param->err_o = errno;
		param->ret_u = ft_strcmp(args2[i], args2[i + 1]);
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
