/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:17:28 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 15:24:04 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	free_exit(t_params *param)
{
	ssize_t	i;

	i = -1;
	if (param->error_occured == 0)
		printf("\n\n%s\n", "Something went wrong... Now exiting");
	while (++i < 10)
		if (param->args1[i])
			free(param->args1[i]);
	i = -1;
	while (++i < 10)
		if (param->args2[i])
			free(param->args2[i]);
	if (param->args1)
		free(param->args1);
	if (param->args2)
		free(param->args2);
	if (param->str_o)
		free(param->str_o);
	if (param->str_u)
		free(param->str_u);
	if (param->buf_o)
		free(param->buf_o);
	if (param->buf_o)
		free(param->buf_u);
	if (param)
		free(param);
	return (-1);
}
