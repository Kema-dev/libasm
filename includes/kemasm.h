/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kemasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:03:15 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/20 15:20:03 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _KEMASM_H
# define _KEMASM_H

// o = original, u = user

typedef struct		s_params
{
	char	*strok;
	char	*strfail;
	char	*errok;
	char	*errfail;
	char	**args1;
	char	**args2;
	char	*buf_o;
	char	*buf_u;
	char	*str_o;
	char	*str_u;
	int		fd;
	int		ret_o;
	int		ret_u;
	int		err_o;
	int		err_u;
	int		error_occured;
}					t_params;

int					struct_init(t_params *param);
int					free_exit(t_params *param);
int					test_strlen(t_params *param);
int					test_strcpy(t_params *param);
int					test_strcmp(t_params *param);
int					test_strdup(t_params *param);

#endif
