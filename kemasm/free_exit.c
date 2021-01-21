/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:17:28 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/21 12:23:16 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	free_exit(t_params *param)
{
	if (param->error_occured != 0)
		printf("\n\n%s\n", "Something went wrong... Now exiting");
	if (param->str_o)
		free(param->str_o);
	if (param->str_u)
		free(param->str_u);
	if (param)
		free(param);
	return (-1);
}
