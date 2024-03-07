NAME		= fractol
SRC_DIR		= src
OBJ_DIR		= obj
SUB_DIR		= utils else

SRCS		= $(addprefix $(SRC_DIR)/utils/, file.c) \
			$(addprefix $(SRC_DIR)/else/, file2.c) \
			$(addprefix $(SRC_DIR)/, main.c)
OBJS		= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INC			= -I incs
RM			= rm -r

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re