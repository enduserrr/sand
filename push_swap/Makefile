# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:35:41 by asalo             #+#    #+#              #
#    Updated: 2024/02/13 12:37:49 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIBFT		= ./libft/libft.a
SRC_DIR		= src
OBJ_DIR		= obj
SUB_DIR		= algo cmnds nodes stack main

SRCS		= $(addprefix $(SRC_DIR)/algo/, turk_sort.c sort_three.c) \
				$(addprefix $(SRC_DIR)/cmnds/, push.c rev_rotate.c rotate.c swap.c) \
				$(addprefix $(SRC_DIR)/nodes/, a_to_b_init.c b_to_a_init.c) \
				$(addprefix $(SRC_DIR)/stack/, main.c init_stack.c split.c stack_utils.c error_free.c)

OBJ_PRE		= $(foreach dir, $(SUB_DIR), $(addprefix $(OBJ_DIR)/, $(dir)))
OBJ			= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

INC			= -I incs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
			@make -C ./libft

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			@$(CC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
			$(RM) $(OBJ)
			@$(RM) -r $(OBJ_DIR)
			@make clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re