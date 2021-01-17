# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 19:29:44 by jjourdan          #+#    #+#              #
#    Updated: 2021/01/17 17:37:26 by jjourdan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

ASM			=	nasm

ASM_FLAGS	=	-f macho64

CC			=	gcc

CC_FLAGS	=	-Wall -Wextra -Werror

MOUL_FLAGS	=	-Wall -Wextra -fsanitize=address

INCLUDES	=	libasm.h

INC_DIR		=	includes

RM			=	rm -rf

NAME		=	libasm.a

MOUL_OUT	=	moulinette.out

SRCS_DIR	=	sources/

SRCS		=	ft_strlen.s\
				ft_strcpy.s \
				ft_strcmp.s \
				ft_strdup.s
				#ft_write.s \
				#ft_read.s \

SRCS_FULL	=	$(addprefix ${SRCS_DIR}, ${SRCS})

OBJS		=	$(SRCS_FULL:.s=.o)

%.o: %.s		$(INC_DIR)/$(INCLUDES)
				$(ASM) $(ASM_FLAGS) $< -o $@

all:			$(NAME)

$(NAME): 		$(OBJS)
				ar rcs $(NAME) $(OBJS)

moulinette:		all
				$(CC) $(MOUL_FLAGS) -I $(INC_DIR) main.c $(NAME) -o $(MOUL_OUT)
				./moulinette.out

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(MOUL_OUT)

re:				fclean all

.PHONY: all, norme, moulinette, clean, fclean, re