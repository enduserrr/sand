# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:37:45 by asalo             #+#    #+#              #
#    Updated: 2023/12/05 11:50:44 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS   		= ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
			ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c \
			ft_tolower.c ft_bzero.c ft_memchr.c ft_putstr_fd.c \
			ft_strlen.c ft_toupper.c ft_calloc.c ft_memcmp.c \
			ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c \
			ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c \
			ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c \
			ft_striteri.c ft_strrchr.c ft_isdigit.c ft_putchar_fd.c \
			ft_strjoin.c ft_strtrim.c

OBJS		= $(SRCS:.c=.o)

SRCSB  		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
       		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \

BOBJS		= $(SRCSB:.c=.o)

NAME		= libft.a
AR			= ar rc
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
					${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean: 	clean
					${RM} ${NAME} ${BOBJS} .bonus

re: 		fclean all 

bonus:		.bonus

.bonus:		$(NAME) $(BOBJS)
					$(AR) $(NAME) $(BOBJS)
					touch	.bonus

.PHONY:		all bonus clean fclean re
