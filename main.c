/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:58:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 13:17:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include "libasm.h"

void test_read()
{
	char	*strok;
	char	*strfail;
	char	*buf1;
	char	*buf2;
	char	*errok;
	char	*errfail;
	int		fd;
	int		ret1;
	int		ret2;
	int		err1;
	int		err2;

	if (!(buf1 = calloc(401, sizeof(char))))
		return ;
	if (!(buf2 = calloc(401, sizeof(char))))
	{
		free(buf1);
		return ;
	}
	printf("Testing read:\n\n");
	errok = "\033[0;32merrno ok!\033[0;37m";
	errfail = "\033[0;31merrno fail!\033[0;37m";
	strok = "\033[0;32mok!\033[0;37m";
	strfail = "\033[0;31mfail!\033[0;37m";

	printf("Test with \"%s\" : ", "main.c");
	fd = open("main.c", O_RDONLY);
	ret1 = read(fd, buf1, 400);
	buf1[400] = 0;
	close(fd);
	fd = open("main.c", O_RDONLY);
	ret2 = ft_read(fd, buf2, 400);
	buf2[400] = 0;
	close(fd);
	if ((strcmp(buf1, buf2) == 0) && (ret1 == ret2))
		printf("%s ret = %d vs %d\n", strok, ret1, ret2);
	else
		printf("%s ret = %d vs %d\n", strfail, ret1, ret2);
	printf("Test with \"%s\" : ", "an empty file");
	fd = open("empty", O_RDONLY);
	ret1 = read(fd, buf1, 400);
	err1 = errno;
	buf1[400] = 0;
	close(fd);
	fd = open("empty", O_RDONLY);
	ret2 = ft_read(fd, buf2, 400);
	err2 = errno;
	buf2[400] = 0;
	close(fd);
	if ((strcmp(buf1, buf2) == 0) && (ret1 == ret2))
		printf("%s ret = %d vs %d ", strok, ret1, ret2);
	else
		printf("%s ret = %d vs %d ", strfail, ret1, ret2);
	if (err1 == err2)
		printf("%s\n", errok);
	else
		printf("%s code (%d) %s vs code (%d) %s\n", errfail, err1, strerror(err1), err2, strerror(err2));
	printf("\n");
	free(buf1);
	free(buf2);
}

void test_write()
{
	char	*strok;
	char	*strfail;
	char	*buf1;
	char	*buf2;
	char	*errok;
	char	*errfail;
	int		fd;
	int		ret1;
	int		ret2;
	int		err1;
	int		err2;

	if (!(buf1 = calloc(401, sizeof(char))))
		return ;
	if (!(buf2 = calloc(401, sizeof(char))))
	{
		free(buf1);
		return ;
	}
	printf("Testing write:\n\n");
	errok = "\033[0;32merrno ok!\033[0;37m";
	errfail = "\033[0;31merrno fail!\033[0;37m";
	strok = "\033[0;32mok!\033[0;37m";
	strfail = "\033[0;31mfail!\033[0;37m";

	printf("Test with \"%s\" : ", "12345");
	fd = open("file1", O_WRONLY);
	ret1 = write(fd, "12345", 5);
	read(fd, buf1, 400);
	buf1[400] = 0;
	close(fd);
	fd = open("file2", O_WRONLY);
	ret2 = ft_write(fd, "12345", 5);
	read(fd, buf1, 400);
	buf1[400] = 0;
	close(fd);
	if ((strcmp(buf1, buf2) == 0) && (ret1 == ret2))
		printf("%s ret = %d vs %d\n", strok, ret1, ret2);
	else
		printf("%s ret = %d vs %d\n", strfail, ret1, ret2);
	
	printf("Test with \"%s\" : ", "a NULL input");
	fd = open("", O_WRONLY);
	ret1 = write(fd, "12345", 5);
	err1 = errno;
	read(fd, buf1, 400);
	buf1[400] = 0;
	close(fd);
	fd = open("", O_WRONLY);
	ret2 = ft_write(fd, "12345", 5);
	err2 = errno;
	read(fd, buf1, 400);
	buf1[400] = 0;
	close(fd);
	if ((strcmp(buf1, buf2) == 0) && (ret1 == ret2))
		printf("%s ret = %d vs %d ", strok, ret1, ret2);
	else
		printf("%s ret = %d vs %d ", strfail, ret1, ret2);
	if (err1 == err2)
			printf("%s\n", errok);
		else
			printf("%s code (%d) %s vs code (%d) %s\n", errfail, err1, strerror(err1), err2, strerror(err2));
	free(buf1);
	free(buf2);
}

int	main(void)
{
	ssize_t	i;
	char	*dest1;
	char	*dest2;
	char	**lencpy;
	char	**cmp;
	char	*strok;
	char	*strfail;
	char	*errok;
	char	*errfail;
	int		err1;
	int		err2;

	i = -1;
	strok = "\033[0;32mcheck ok!\033[0;37m";
	strfail = "\033[0;31mcheck fail!\033[0;37m";
	errok = "\033[0;32merrno ok!\033[0;37m";
	errfail = "\033[0;31merrno fail!\033[0;37m";
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
	lencpy[2] = "12345";
	lencpy[3] = "1234567890";
	lencpy[4] = "4";
	lencpy[5] = "5";
	lencpy[6] = NULL;
	cmp[0] = "";
	cmp[1] = "";
	cmp[2] = "1";
	cmp[3] = "1";
	cmp[4] = "2";
	cmp[5] = "1";
	cmp[6] = "111";
	cmp[7] = "111";
	cmp[8] = "112";
	cmp[9] = "";
	cmp[10] = NULL;

	system("clear");
	printf("\033[0;37m\nStarting tests !\n");
	printf("\n\nTesting strlen:\n\n");
	while (lencpy[++i])
	{
		printf("Test with \"%s\" : ", lencpy[i]);
		if ((ft_strlen(lencpy[i]) - strlen(lencpy[i])) == 0)
			printf("%s ", strok);
		else
			printf("%s return %d vs %d ", strfail, strlen(lencpy[i]), ft_strlen(lencpy[i]));
		strlen(lencpy[i]);
		err1 = errno;
		ft_strlen(lencpy[i]);
		err2 = errno;
		if (err1 == err2)
			printf("%s\n", errok);
		else
			printf("%s code (%d) %s vs code (%d) %s\n", errfail, err1, strerror(err1), err2, strerror(err2));
	}
	i = -1;
	printf("\n");

	printf("Testing strcpy:\n\n");
	while (lencpy[++i])
	{
		printf("Test with \"%s\" : ", lencpy[i]);
		if (strcmp(strcpy(dest1, lencpy[i]), ft_strcpy(dest1, lencpy[i])) == 0)
			printf("%s ", strok);
		else
			printf("%s return %d vs %d ", strfail, strcpy(dest1, lencpy[i]), ft_strcpy(dest1, lencpy[i]));
		strcpy(dest1, lencpy[i]);
		err1 = errno;
		ft_strcpy(dest1, lencpy[i]);
		err2 = errno;
		if (err1 == err2)
			printf("%s\n", errok);
		else
			printf("%s code (%d) %s vs code (%d) %s\n", errfail, err1, strerror(err1), err2, strerror(err2));
	}
	i = -1;
	printf("\n");

	printf("Testing strcmp:\n\n");
	while (cmp[++i + 1])
	{
		printf("Test with \"%s\" and \"%s\" : ", cmp[i], cmp[i + 1]);
		if ((ft_strcmp(cmp[i], cmp[i + 1]) - strcmp(cmp[i], cmp[i + 1])) == 0)
			printf("%s ", strok);
		else
			printf("%s return %d vs %d ", strfail, strcmp(cmp[i], cmp[i + 1]), ft_strcmp(cmp[i], cmp[i + 1]));
		strcmp(cmp[i], cmp[i + 1]);
		err1 = errno;
		ft_strcmp(cmp[i], cmp[i + 1]);
		err2 = errno;
		if (err1 == err2)
			printf("%s\n", errok);
		else
			printf("%s code (%d) %s vs code (%d) %s\n", errfail, err1, strerror(err1), err2, strerror(err2));
	}
	free (cmp);
	i = -1;
	printf("\n");

	printf("Testing strdup:\n\n");
	while (lencpy[++i])
	{
		printf("Test with \"%s\" : ", lencpy[i]);
		free(dest1);
		free(dest2);
		dest1 = strdup(lencpy[i]);
		err1 = errno;
		dest2 = ft_strdup(lencpy[i]);
		err2 = errno;
		if (strcmp(dest1, dest2) == 0)
			printf("%s ", strok);
		else
			printf("%s return %s vs %s ", strfail, dest1, dest2);
		if (err1 == err2)
			printf("%s\n", errok);
		else
			printf("%s code (%d) %s vs code (%d) %s\n", errfail, err1, strerror(err1), err2, strerror(err2));
	}
	i = -1;
	printf("\n");

	free(dest1);
	free(dest2);
	free(lencpy);

	test_read();
	test_write();

	printf("\n\nAll tests done !\n");
	return (0);
}
