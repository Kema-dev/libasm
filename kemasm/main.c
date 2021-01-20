/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:59:36 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 13:42:11 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int	main(void)
{
	t_params *param;

	if (!(param = calloc(1, sizeof(t_params))))
		return (-1);

	

	free(param);
	return (0);
}
