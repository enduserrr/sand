# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:35:41 by asalo             #+#    #+#              #
#    Updated: 2024/02/18 12:13:25 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIBFT		= ./libft/libft.a
SRC_DIR		= src
OBJ_DIR		= obj
SUB_DIR		= cmnds nodes stack

SRCS		= $(addprefix $(SRC_DIR)/sort/, p.c rr.c r.c s.c sort.c) \
				$(addprefix $(SRC_DIR)/init/, init_nodes.c init_stack.c) \
				$(addprefix $(SRC_DIR)/stack/, split.c stack_utils.c error_free.c) \
				$(addprefix $(SRC_DIR)/, main.c)

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