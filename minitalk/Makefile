C_NAME		= client
S_NAME		= server
SRC_DIR		= src
OBJ_DIR		= obj

C_SRCS		= $(addprefix $(SRC_DIR)/, client.c)
S_SRCS		= $(addprefix $(SRC_DIR)/, server.c)
C_OBJ		= $(subst $(SRC_DIR), $(OBJ_DIR), $(C_SRCS:.c=.o)) $(SRCS:.c=.o)
S_OBJ		=$(subst $(SRC_DIR), $(OBJ_DIR), $(S_SRCS:.c=.o))
INC			= -I incs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

MAKECCH		= .make_cache

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:		$(C_NAME) $(S_NAME)

$(C_NAME): 	$(C_OBJ) $(MAKECCH)
			@$(CC) $(C_OBJ) -o $(C_NAME)

$(S_NAME):	$(S_NAME) $(MAKECCH)
			@$(CC) $(S_OBJ) -o $(S_NAME)

clean:		$(RM) $(C_OBJ)
			$(RM) $(S_OBJ)
			$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(C_NAME)
			$(RM) $(S_NAME)

re:			fclean all

.PHONY: all clean fclean re