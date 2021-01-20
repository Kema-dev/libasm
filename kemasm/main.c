/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:59:36 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 15:24:33 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kemasm.h"
#include "../includes/libasm.h"

int	main(void)
{
	t_params	*param;
	ssize_t		i;

	i = -1;
	if (!(param = calloc(1, sizeof(t_params))))
		return (-1);
	if (struct_init(param) != 0)
		return (-1);

	printf("\033c\033[0;37m\nStarting tests!");

	printf("\n\nTesting strlen\n\n");
	if (!(test_strlen(param)))
		return (free_exit(param));
	if (!(test_strcpy(param)))
		return (free_exit(param));
	if (!(test_strcmp(param)))
		return (free_exit(param));
	if (!(test_strdup(param)))
		return (free_exit(param));
	
	printf("\n\nAll tests done !\n");
	param->error_occured = -1;
	free_exit(param);
	return (0);
}
