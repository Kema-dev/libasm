/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:58:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/17 18:41:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libasm.h"

int	main(void)
{
	ssize_t	i;
	char	*dest1;
	char	*dest2;
	char	**lencpy;
	char	**cmp;
	char	*strok;
	char	*strfail;

	i = -1;
	strok = "\033[0;32mok!\033[0;37m";
	strfail = "\033[0;31mfail!\033[0;37m";
	if (!(dest1 = calloc(100, sizeof(char))))
		return (-1);
	if (!(dest2 = calloc(100, sizeof(char))))
	{
		free(dest1);
		return (-1);
	}
	if (!(lencpy = calloc(100, sizeof(char *))))
	{
		free(dest1);
		free(dest2);
		return (-1);
	}
	if (!(cmp = calloc(100, sizeof(char *))))
	{
		free(dest1);
		free(dest2);
		free(lencpy);
		return (-1);
	}
	lencpy[0] = "";
	lencpy[1] = "1";
	lencpy[2] = "2";
	lencpy[3] = "";
	lencpy[4] = "4";
	lencpy[5] = "5";
	lencpy[6] = NULL;
	cmp[0] = "";
	cmp[1] = "";
	cmp[2] = "2";
	cmp[3] = "3";
	cmp[4] = "4";
	cmp[5] = "5";
	cmp[6] = "6";
	cmp[7] = "7";
	cmp[8] = "8";
	cmp[9] = "9";
	cmp[10] = NULL;

	printf("\n\nTesting strlen:\n\n");

	while (lencpy[++i])
	{
		printf("Test with \"%s\" : ", lencpy[i]);
		if ((ft_strlen(lencpy[i]) - strlen(lencpy[i])) == 0)
			printf("%s\n", strok);
		else
			printf("%s\n", strfail);
	}
	i = -1;
	printf("\n");

	printf("Testing strcpy:\n\n");
	while (lencpy[++i])
	{
	printf("Test with \"%s\" : ", lencpy[i]);
	if (strcmp(strcpy(dest1, lencpy[i]), ft_strcpy(dest1, lencpy[i])) == 0)
		printf("%s\n", strok);
	else
		printf("%s\n", strfail);
	}
	i = -1;
	printf("\n");

	printf("Testing strcmp:\n\n");
	while (cmp[++i + 1])
	{
	printf("Test with \"%s\" and \"%s\" : ", cmp[i], cmp[i + 1]);
	if ((ft_strcmp(cmp[i], cmp[i + 1]) - strcmp(cmp[i], cmp[i + 1])) == 0)
		printf("%s\n", strok);
	else
		printf("%s\n", strfail);
	i++;
	}
	free (cmp);
	i = -1;
	printf("\n");

	printf("Testing strdup:\n\n");
	while (lencpy[++i])
	{
	printf("Test with \"%s\" : ", lencpy[i]);
	dest1 = strdup(lencpy[i]);
	dest2 = ft_strdup(lencpy[i]);
	if (strcmp(dest1, dest2) == 0)
		printf("%s\n", strok);
	else
		printf("%s\n", strfail);
	}
	i = -1;
	printf("\n");

	free(dest1);
	free(dest2);
	free (lencpy);
	return (0);
}
