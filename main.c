/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:58:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/17 09:18:45 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libasm.h"

#define RED \033[0;31m
#define GREEN \033[0;32m
#define WHITE \033[0;37m

int	main(void)
{
	ssize_t	i;
	char	*dest;
	char	**str;

	i = -1;
	if (!(dest = calloc(100, sizeof(char))))
		return (-1);
	if (!(str = calloc(100, sizeof(char *))))
		return (-1);
	str[0] = "0";
	str[1] = "1";
	str[2] = "2";
	str[3] = "3";
	str[4] = "4";
	str[5] = NULL;

	printf("\n\nTesting strlen:\n\n");

	while (str[++i])
	{
		printf("Test with \"%s\" : ", str[i]);
		if ((ft_strlen(str[i]) - strlen(str[i])) == 0)
			printf("\033[0;32mok!\n\033[0;37m");
		else
			printf("\033[0;31mfail!\n\033[0;37m");
	}
	i = -1;
	printf("\n");

	printf("Testing strcpy:\n\n");
	while (str[++i])
	{
	printf("Test with \"%s\" : ", str[i]);
	if (strcmp(strcpy(dest, str[i]), ft_strcpy(dest, str[i])) == 0)
		printf("\033[0;32mok!\n\033[0;37m");
	else
		printf("\033[0;31mfail!\n\033[0;37m");
	}
	i = -1;
	printf("\n");


	free (str);
	free (dest);
	return (0);
}
