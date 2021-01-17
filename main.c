/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:58:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/17 16:36:05 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libasm.h"

void check_write()
{
	char *hello_world = "Coucou\n";
	char *empty = "";

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, hello_world, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, empty, 0));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, empty, 0));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(-7, NULL, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(-7, NULL, 7));
	// printf("\n");
	
}

void check_read()
{
	int fd = open("main.c", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	printf("%-20s: \n", "header main.c | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("main.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header main.c | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("test", O_RDONLY);
	printf("%-20s: \n", "file test | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("test", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "file test | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("wrong", O_RDONLY);
	printf("%-20s: \n", "wrong | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "wrong | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
}

int	main(void)
{
	ssize_t	i;
	int		fd1;
	int		fd2;
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
	lencpy[0] = "0";
	lencpy[1] = "";
	lencpy[2] = "2";
	lencpy[3] = "";
	lencpy[4] = "4";
	lencpy[5] = "5";
	lencpy[6] = NULL;
	cmp[0] = "1";
	cmp[1] = "1";
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

	/*printf("\n\nTesting read:\n\n");
	fd1 = open("testfile1", S_IRWXU);
	fd2 = open("testfile2", S_IRWXU);
	while (lencpy[++i])
	{
		ft_read(fd1, dest1, 100);
		read(fd2, dest2, 100);
		printf("Test with \"%s\" : ", lencpy[i]);
		if (ft_strcmp(dest1, dest2) == 0)
			printf("%s\n", strok);
		else
			printf("%s\n", strfail);
	}
	close(fd1);
	close(fd2);
	i = -1;
	printf("\n");

	printf("\n\nTesting write:\n\n");
	fd1 = open("testfile1", O_CREAT, S_IRWXU);
	fd2 = open("testfile2", O_CREAT, S_IRWXU);
	while (lencpy[++i])
	{
		ft_write(fd1, lencpy[i], 100);
		write(fd2, lencpy[i], 100);
		read(fd1, dest1, 100);
		read(fd2, dest2, 100);
		printf("Test with \"%s\" : ", lencpy[i]);
		if (ft_strcmp(dest1, dest2) == 0)
			printf("%s\n", strok);
		else
			printf("%s\n", strfail);
	}
	close(fd1);
	close(fd2);
	i = -1;
	printf("\n");*/

	check_write();
	check_read();

	free(dest1);
	free(dest2);
	free (lencpy);
	return (0);
}
