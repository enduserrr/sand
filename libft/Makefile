# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:37:45 by asalo             #+#    #+#              #
#    Updated: 2024/02/07 12:33:08 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= is to mem str put lst gnl printf

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(DIR_SRCS)/is/ft_isalnum.c $(DIR_SRCS)/is/ft_isalpha.c \
				$(DIR_SRCS)/is/ft_isascii.c $(DIR_SRCS)/is/ft_isdigit.c \
				$(DIR_SRCS)/is/ft_isprint.c $(DIR_SRCS)/is/ft_isspace.c \
				$(DIR_SRCS)/to/ft_atoi.c $(DIR_SRCS)/to/ft_itoa.c \
				$(DIR_SRCS)/to/ft_atol.c \
				$(DIR_SRCS)/to/ft_tolower.c $(DIR_SRCS)/to/ft_toupper.c \
				$(DIR_SRCS)/mem/ft_bzero.c $(DIR_SRCS)/mem/ft_calloc.c \
				$(DIR_SRCS)/mem/ft_memchr.c $(DIR_SRCS)/mem/ft_memcmp.c \
				$(DIR_SRCS)/mem/ft_memcpy.c $(DIR_SRCS)/mem/ft_memmove.c \
				$(DIR_SRCS)/mem/ft_memset.c \
				$(DIR_SRCS)/put/ft_putchar_fd.c $(DIR_SRCS)/put/ft_putendl_fd.c \
				$(DIR_SRCS)/put/ft_putnbr_fd.c $(DIR_SRCS)/put/ft_putstr_fd.c \
				$(DIR_SRCS)/str/ft_split.c $(DIR_SRCS)/str/ft_strchr.c \
				$(DIR_SRCS)/str/ft_strdup.c $(DIR_SRCS)/str/ft_striteri.c \
				$(DIR_SRCS)/str/ft_strjoin.c $(DIR_SRCS)/str/ft_strlcat.c \
				$(DIR_SRCS)/str/ft_strlcpy.c $(DIR_SRCS)/str/ft_strlen.c \
				$(DIR_SRCS)/str/ft_strmapi.c $(DIR_SRCS)/str/ft_strncmp.c \
				$(DIR_SRCS)/str/ft_strnstr.c $(DIR_SRCS)/str/ft_strrchr.c \
				$(DIR_SRCS)/str/ft_strtrim.c $(DIR_SRCS)/str/ft_substr.c \
				$(DIR_SRCS)/lst/ft_lstadd_back_bonus.c \
				$(DIR_SRCS)/lst/ft_lstadd_front_bonus.c \
				$(DIR_SRCS)/lst/ft_lstclear_bonus.c \
				$(DIR_SRCS)/lst/ft_lstdelone_bonus.c \
				$(DIR_SRCS)/lst/ft_lstiter_bonus.c \
				$(DIR_SRCS)/lst/ft_lstlast_bonus.c \
				$(DIR_SRCS)/lst/ft_lstnew_bonus.c \
				$(DIR_SRCS)/lst/ft_lstsize_bonus.c \
				$(DIR_SRCS)/gnl/get_next_line_utils.c \
				$(DIR_SRCS)/gnl/get_next_line.c \
				$(DIR_SRCS)/printf/ft_print_format.c $(DIR_SRCS)/printf/ft_printf.c
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

INC			= -I incs/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re