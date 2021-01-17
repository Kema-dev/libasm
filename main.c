/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:58:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/16 21:03:26 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libasm.h"

int	main(void)
{
	printf("%ld\n", ft_strlen("\12345"));
	printf("%ld\n", strlen("\12345"));
	return (0);
}
