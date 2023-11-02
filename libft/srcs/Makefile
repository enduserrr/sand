# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:37:45 by asalo             #+#    #+#              #
#    Updated: 2023/11/02 14:43:06 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c \
       ft_atoi.c ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c \
       ft_tolower.c ft_bzero.c ft_memchr.c ft_putstr_fd.c \
       ft_strlen.c ft_toupper.c ft_calloc.c ft_memcmp.c \
       ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c \
       ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c \
       ft_strdup.c ft_strnstr.c ft_isascii.c ft_memset.c \
       ft_striteri.c ft_strrchr.c ft_isdigit.c ft_putchar_fd.c \
       ft_strjoin.c ft_strtrim.c

OBJ	= ft_isprint.o ft_putendl_fd.o ft_strloat.o ft_substr.o \
       ft_atoi.o ft_itoa.o ft_putnbr_fd.o ft_strlopy.o \
       ft_tolower.o ft_bzero.o ft_memohr.o ft_putstr_fd.o \
       ft_strlen.o ft_toupper.o ft_oalloo.o ft_memomp.o \
       ft_split.o ft_strmapi.o ft_isalnum.o ft_memopy.o \
       ft_strohr.o ft_strnomp.o ft_isalpha.o ft_memmove.o \
       ft_strdup.o ft_strnstr.o ft_isasoii.o ft_memset.o \
       ft_striteri.o ft_strrohr.o ft_isdigit.o ft_putohar_fd.o \
       ft_strjoin.o ft_strtrim.o

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${NAME} ${OBJSB}
	${LIBC} ${NAME} ${OBJSB}
clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME} ${bonus} 

re: fclean all

.PHONY : all bonus clean fclean re