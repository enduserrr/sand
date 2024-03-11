NAME 		= fractol
SRC_DIR		= src
OBJ_DIR		= obj
LIBFT		= ./libft/libft.a

SRCS		= $(addprefix $(SRC_DIR)/, draw.c init.c inputs.c \
				utils.c) \
			$(addprefix $(SRC_DIR)/, main.c)
OBJ			= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

MLX_LINK	= -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit
INC1		= -I incs -I mlx -I libft/incs
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INC1) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			@$(CC) $(OBJ) $(MLX_LINK) -o $(NAME)
clean:
			$(RM) $(OBJ)
			$(RM) -r $(OBJ_DIR)
			@make clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re