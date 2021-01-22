/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 20:38:57 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/22 16:25:16 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBASM_H
# define _LIBASM_H

ssize_t		ft_read(int fd, void *buf, size_t count);
ssize_t		ft_write(int fd, const void *buf, size_t count);
size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);

int 		*__errno_location(void);

#endif
