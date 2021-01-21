/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:00:14 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/21 11:21:16 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	test_read(t_params *param)
{
	char	*file[12] = {"", "", "", "12345", "12345", "12345", "12345", "12345", "empty", "empty", "empty", "main.c"};
	int		buf_size[12] = {-1, 0, 5, -1, 0, 3, 5, 8, -1, 0, 5, 400};
	ssize_t	i;

	i = -1;
	printf("\n\nTesting read:\n\n");
	param->fd = creat("empty", O_WRONLY);
	close(param->fd);
	param->fd = creat("empty", O_WRONLY);
	write(param->fd, "12345", 5);
	close(param->fd);
	while (++i < 12)
	{
		printf("Test with \"%s\" file and %d buffer size: ", file[i], buf_size[i]);
		param->fd = open(file[i], O_RDONLY);
		param->ret_o = read(param->fd, param->str_o, buf_size[i]);
		param->err_o = errno;
		close(param->fd);
		param->fd = open(file[i], O_RDONLY);
		param->ret_u = ft_read(param->fd, param->str_u, buf_size[i]);
		param->err_u = errno;
		close(param->fd);
		if (strcmp(param->str_o, param->str_u) == 0)
			printf("%s ", param->strok);
		else
			printf("%s you returned %s, expected %s", param->strfail, param->str_u, param->str_o);
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
