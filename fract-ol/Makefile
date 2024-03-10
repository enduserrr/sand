NAME 	= fractol
SRC_DIR	= src
OBJ_DIR	= obj

SRCS	= $(addprefix $(SRC_DIR)/bin/, draw.c init.c inputs.c \
			julia.c mandelbrot.c utils.c) \
			$(addprefix $(SRC_DIR)/, main.c)
OBJ		= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
INC		= -I incs
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

$(OBJ_DIR)/%.o :	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INC) -Imlx -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
			$(RM) $(OBJ)
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all