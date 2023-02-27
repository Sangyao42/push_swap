NAME = push_swap
TEST = test.c
PS = push_swap.c
CC = gcc
CFLAGS =  -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g3
TEST_DIR = ./spec/
SRC_DIR = src/
OBJ_DIR = obj/
# SRCS = $(addprefix $(SRC_DIR),input_checker.c)\
# 		$(addprefix $(SRC_DIR),input_getter.c)\
# 		$(addprefix $(SRC_DIR),input_utils.c)\
# 		$(addprefix $(SRC_DIR),prime_operations.c)\
# 		$(addprefix $(SRC_DIR),secondary_operations.c)\
# 		$(addprefix $(SRC_DIR),operation_utils.c)\

SRCS = input_checker.c \
		input_getter.c \
		input_utils.c \
		prime_operations.c \
		secondary_operations.c \
		operation_utils.c
OBJS = $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
HEADER = -I ./include -I ./lib/GNL/src/ -I ./lib/Libft/
LIBFT = "./lib/Libft"
LIBGNL = "./lib/GNL"

all: $(NAME)

$(NAME): $(OBJS) $(addprefix $(SRC_DIR),$(PS)) libft libgnl
	$(CC) $(CFLAGS) $(HEADER) -L $(LIBFT) -lft -L $(LIBGNL) -lgnl $(addprefix $(SRC_DIR),$(PS)) $(OBJS) -o $(NAME)

test: $(OBJS) $(addprefix $(TEST_DIR),$(TEST)) libft libgnl
	$(CC) $(CFLAGS) $(HEADER) -L $(LIBFT) -lft -L $(LIBGNL) -lgnl $(addprefix $(TEST_DIR),$(TEST)) $(OBJS) -o test

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(HEADER) -c $^ -o $@

# $(OBJS): $(SRCS)
# 	$(CC) $(CFLAGS) $(HEADER) -L$(LIBFT) -lft -L$(LIBGNL) -lgnl -c $(SRCS)

clean:
	rm -f $(OBJS)
	@make fclean -C ./lib/LIBFT/
	@make fclean -C ./lib/GNL/

fclean: clean
	rm -f $(NAME)
	rm -f test


re:
	fclean all

bonus:

libft:
	@make -C ./lib/Libft/

libgnl:
	@make -C ./lib/GNL/

.PHONY: all clean fclean re
