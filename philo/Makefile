NAME	= philo
SRCS	= init.c threading.c bones.c meat.c main.c
OBJ_DIR = obj
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCS 	= -I philo.h
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -fr

$(OBJ_DIR)/%.o :	%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re