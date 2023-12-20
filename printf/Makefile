# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:33:23 by asalo             #+#    #+#              #
#    Updated: 2023/12/20 21:36:21 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		= ft_printf.c ft_print_char.c ft_print_digit.c ft_print_ptr.c\
				ft_print_str.c ft_print_uint.c
INC 		= ft_printf.h
OBJS		= ft_printf.o ft_print_char.o ft_print_digit.o ft_print_ptr.o\
				ft_print_str.o ft_print_uint.o
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC}

$(NAME) :	${OBJS}
			ar rc ${NAME} ${OBJS}

all: 		$(NAME)

clean :
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re