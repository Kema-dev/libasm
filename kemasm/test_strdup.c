/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:05:19 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/26 14:24:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	test_strdup(t_params *param)
{
	ssize_t	i;
	char	*args1[8] = {"/xff", "", "", "/xff", "1", "12345", "12345\07890", "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"};

	i = -1;
	printf("\n\nTesting strdup:\n\n");
	while (++i < 8)
	{
		printf("Test with \"%s\" : ", args1[i]);
		free(param->str_o);
		free(param->str_u);
		errno = -1;
		if (!(param->str_o = strdup(args1[i])))
			return (free_exit(param));
		param->err_o = errno;
		errno = -1;
		if (!(param->str_u = ft_strdup(args1[i])))
			return (free_exit(param));
		param->err_u = errno;
		if (strcmp(param->str_o, param->str_u) == 0)
			printf("%s ", param->strok);
		else
			printf("%s you returned %s, expected %s ", param->strfail, param->str_u, param->str_o);
		if (param->err_o == param->err_u)
			printf("%s\n", param->errok);
		else
			printf("%s your errno code is (%d) %s, expected (%d) %s\n", param->errfail, param->err_u, strerror(param->err_u), param->err_o, strerror(param->err_o));
	}
	return (0);
}
