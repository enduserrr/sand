# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:35:41 by asalo             #+#    #+#              #
#    Updated: 2024/02/08 11:33:47 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap.a

LIBFT		= libft
SRC_DIR		= src
OBJ_DIR		= obj
SUB_DIR		= algo cmnds nodes stack

SRCS		= $(addprefix $(SRC_DIR)/algo/, turk_sort.c sort_three.c) \
				$(addprefix $(SRC_DIR)/cmnds/, push.c rev_rotate.c rotate.c swap.c) \
				$(addprefix $(SRC_DIR)/nodes/, a_to_b_init.c b_to_a_init.c) \
				$(addprefix $(SRC_DIR)/stack/, init_stack.c split.c stack_utils.c error_free.c)
				
OBJ_PRE		= $(foreach dir, $(SUB_DIR), $(addprefix $(OBJ_DIR)/, $(dir)))
OBJS		= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

INC			= -I incs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
					@mkdir -p $(dir $@)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
			@ar -rcs $(NAME) $(OBJS)

$(LIBFT):
			@make -C $(LIBFT)

clean:
			$(RM) $(OBJS)
			@$(RM) -r $(OBJ_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re $(LIBFT)