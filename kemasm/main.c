/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:59:36 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 17:39:39 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	main(void)
{
	t_params	*param;

	if (!(param = calloc(1, sizeof(t_params))))
		return (-1);
	if (struct_init(param) != 0)
		return (free_exit(param));

	printf("\033c\033[0;37m\nStarting tests!");

	printf("\n\nTesting strlen\n\n");
	if (!(test_strlen(param)))
		return (free_exit(param));
	if (!(struct_reset(param)))
		return(-1);

	if (!(test_strcpy(param)))
		return (free_exit(param));
	if (!(struct_reset(param)))
		return(-1);

	if (!(test_strcmp(param)))
		return (free_exit(param));
	if (!(struct_reset(param)))
		return(-1);

	if (!(test_strdup(param)))
		return (free_exit(param));
	if (!(struct_reset(param)))
		return(-1);

	if (!(test_read(param)))
		return (free_exit(param));
	if (!(struct_reset(param)))
		return(-1);

	if (!(test_write(param)))
		return (free_exit(param));

	printf("\n\nAll tests done !\n");
	param->error_occured = -1;
	free_exit(param);
	return (0);
}
