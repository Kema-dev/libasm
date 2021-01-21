/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:28:38 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/21 12:31:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	struct_reset(t_params *param)
{
	if (!(param))
		free_exit(param);
	if (!(param = calloc(1, sizeof(t_params))))
		return (-1);
	struct_init(param);
	return (0);
}
