# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:33:23 by asalo             #+#    #+#              #
#    Updated: 2023/12/13 17:20:38 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	ft_printf.c ft_printf_utils.c

OBJS 		= $(SRCS:.c=.o)

NAME		= libftprintf.a
AR			= ar rc
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

${NAME}: 	${OBJS}
					${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean: 	clean
					${RM} ${NAME}

re: 		fclean all 

.PHONY:		all clean fclean re