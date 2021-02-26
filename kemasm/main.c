/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:59:36 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/26 15:14:56 by jjourdan         ###   ########lyon.fr   */
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

	printf("\033c\033[0;37m\nStarting tests!\n");

	if (test_strlen(param) != 0)
		return (free_exit(param));
	if (struct_reset(param) != 0)
		return (-1);

	if (test_strcpy(param) != 0)
		return (free_exit(param));
	if (struct_reset(param) != 0)
		return (-1);

	if (test_strcmp(param) != 0)
		return (free_exit(param));
	if (struct_reset(param) != 0)
		return (-1);

	if (test_strdup(param) != 0)
		return (free_exit(param));
	if (struct_reset(param) != 0)
		return (-1);

	if (test_read(param) != 0)
		return (free_exit(param));
	if (struct_reset(param) != 0)
		return (-1);

	if (test_write(param) != 0)
		return (free_exit(param));

	printf("\n\nAll tests done !\nKeep in mind that it doesn't check with any \"NULL\" value but with \"\" and that just a few errno values are tested\n");
	param->error_occured = 0;
	free_exit(param);
	return (0);
}
