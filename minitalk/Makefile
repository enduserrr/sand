C_NAME		= client
S_NAME		= server
SRC_DIR		= src
OBJ_DIR		= obj
C_SRCF		= client
S_SRCF		= server

C_SRCS		= $(addprefix $(SRC_DIR)/, $(addsuffix .c. $(C_SRCF)))
C_OBJ		= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(C_SRCF)))

S_SRCS		= $(addprefix $(SRC_DIR)/, $(addsuffix .c. $(S_SRCF)))
S_OBJ		= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(S_SRCF)))
INC			= -I incs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f


$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all:		$(C_NAME) $(S_NAME)

$(C_NAME): 	$(C_OBJ)
			@$(CC) $(C_OBJ) -o $(C_NAME)

$(S_NAME):	$(S_NAME)
			@$(CC) $(S_OBJ) -o $(S_NAME)

clean:		$(RM) -r $(OBJ_DIR)

fclean:		clean
			$(RM) $(C_NAME)
			$(RM) $(S_NAME)

re:			fclean all

.PHONY: all clean fclean re