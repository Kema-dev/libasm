/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:44:59 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/26 15:14:30 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	test_write(t_params *param)
{
	char	*file_o[13] = {"", "", "", "", "", "", "", "", "file_o", "file_o", "file_o", "file_o", "file_o"};
	char	*file_u[13] = {"", "", "", "", "", "", "", "", "file_u", "file_u", "file_u", "file_u", "file_u"};
	char	*input[13] = {"", "", "", "12345", "12345", "12345", "12345", "12345", "12345", "12345" "12345", "12345", "12345", ""};
	int		buf_size[13] = {-1, 0, 5, -1, 0, 3, 5, 8, -1, 0, 3, 5, 8};
	ssize_t	i;

	i = -1;
	printf("\n\nTesting write:\n\n");
	while (++i < 13)
	{
		printf("Test with \"%s\" file and buffer size %d with \"%s\" input : ", file_o[i], buf_size[i], input[i]);
		errno = -1;
		param->fd = open(file_o[i], O_CREAT, S_IRWXO);
		param->fd = -1;
		param->ret_o = write(param->fd, input[i], buf_size[i]);
		param->err_o = errno;
		read(param->fd, param->str_o, 10);
		close(param->fd);
		errno = -1;
		param->fd = open(file_u[i], O_CREAT, S_IRWXO);
		param->ret_u = ft_write(param->fd, input[i], buf_size[i]);
		param->err_u = errno;
		read(param->fd, param->str_u, 10);
		close(param->fd);
		if (strcmp(param->str_o, param->str_u) == 0)
			printf("%s ", param->strok);
		else
			printf("%s you returned %s, expected %s ", param->strfail, param->str_u, param->str_o);
		if (param->ret_o == param->ret_u)
			printf("%s ", param->strok);
		else
			printf("%s you returned %d, expected %d ", param->strfail, param->ret_u, param->ret_o);
		if (param->err_o == param->err_u)
			printf("%s\n", param->errok);
		else
			printf("%s your errno code is (%d) %s, expected (%d) %s\n", param->errfail, param->err_u, strerror(param->err_u), param->err_o, strerror(param->err_o));
		remove(file_o[i]);
		remove(file_u[i]);
	}
	return (0);
}
