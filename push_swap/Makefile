# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 18:35:41 by asalo             #+#    #+#              #
#    Updated: 2024/01/27 20:37:14 by asalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap.a

SRCS_DIR	= srcs
OBJS_DIR	= objs
SUBDIRS		= algo cmnds nodes stack
LIBFT		= libft

SRCS_RULE	= $(foreach dir, $(SUBDIRS), $(addprefix $(SRCS_DIR)/, $(dir)))
OBJS_RULE	= $(foreach dir, $(SUBDIRS), $(addprefix $(OBJS_DIR)/, $(dir)))
SRCS		= $(SRCS_DIR)/algo/turk_sort.c $(SRCS_DIR)/algo/sort_three.c \
				$(SRCS_DIR)/cmnds/push.c $(SRCS_DIR)/cmnds/rev_rotate.c \
				$(SRCS_DIR)/cmnds/rotate.c $(SRCS_DIR)/cmnds/swap.c \
				$(SRCS_DIR)/nodes/a_to_b_init.c $(SRCS_DIR)/nodes/b_to_a_init.c \
				$(SRCS_DIR)/stack/init_stack.c $(SRCS_DIR)/stack/split.c \
				$(SRCS_DIR)/stack/stack_utils.c $(SRCS_DIR)/stack/error_free.c
OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

INC			= -I incs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@
					

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			@ar -rcs $(NAME) $(OBJS)
			@make -C /libft $(LIBFT)
clean:
			$(RM) $(OBJS)
			@$(RM) -r $(OBJS_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re