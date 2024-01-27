# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:35:41 by asalo             #+#    #+#              #
#    Updated: 2024/01/27 19:03:08 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
ARCHIVE		= push_swap.a
SRCS_DIR	= srcs
OBJS_DIR	= objs
SUBDIRS		= algo cmnds nodes stack
LIBFT		= ./libft/libft.a

SRCS_RULE	= $(foreach dir, $(SUBDIRS), $(addprefix $(SRCS_DIR)/, $(dir)))
OBJS_RULE	= $(foreach dir, $(SUBDIRS), $(addprefix $(OBJS_DIR)/, $(dir)))
SRCS		= $(SRC_DIR)algo/turk_sort.c $(SRC_DIR)algo/sort_three.c \
				$(SRC_DIR)cmnds/push.c $(SRC_DIR)cmnds/rev_rotate.c \
				$(SRC_DIR)cmnds/rotate.c $(SRC_DIR)cmnds/swap.c \
				$(SRC_DIR)nodes/a_to_b_init.c $(SRC_DIR)nodes/b_to_a_init.c \
				$(SRC_DIR)stack/init_stack.c $(SRC_DIR)stack/split.c \
				$(SRC_DIR)stack/stack_utils.c $(SRC_DIR)stack/error_free.c

OBJS		= $(subst $(DIR_SRCS), $(OBJS_DIR), $(SRCS:.c=.o))

INC			= -I incs/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(OBJS_DIR)/%.o :	$(SRC_DIR)/%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
			@make -C ./libft

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)
			@$(RM) -r $(OBJS_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re