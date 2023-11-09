# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 15:17:29 by asalo             #+#    #+#              #
#    Updated: 2023/08/30 10:24:00 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRE		= ./srcs/
SRCS	= ${addprefix ${PRE}, ${SRC}}
SRC		= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
INC 	= includes
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror

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