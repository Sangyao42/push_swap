NAME = push_swap
# TEST = test.c
BONUS_NAME = checker
BONUS = checker.c
PS = push_swap.c
CC = gcc
CFLAGS =  -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g3
TEST_DIR = ./spec/
SRC_DIR = src/
OBJ_DIR = obj/

SRCS = input_checker.c \
		input_utils.c \
		prime_operations.c \
		secondary_operations.c \
		operations_utils.c \
		ps_initializer.c \
		ps_free.c \
		stack_status.c \
		indexer.c \
		small_nums_sorter.c \
		small_nums_sorter_utils.c \
		partitioner.c \
		large_nums_sorter.c \
		element_indexer.c \
		commands_selector.c \
		command.c
SRCS += input_getter.c
# SRCS += input_getter_2.c
# SRC_PRINTER = $(addprefix $(TEST_DIR), stack_printer.c)
# OBJ_PRINTER = $(addprefix $(OBJ_DIR), stack_printer.o)
OBJS = $(addprefix $(OBJ_DIR),$(SRCS:.c=.o))
BONUS_SRCS = command_checker.c
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(BONUS_SRCS:.c=.o))
HEADER = -I ./include -I ./lib/GNL/src/ -I ./lib/Libft/
LIBFT = "./lib/Libft"
LIBGNL = "./lib/GNL"

all: $(NAME)

$(NAME): $(OBJS) $(addprefix $(SRC_DIR),$(PS)) libft libgnl
	$(CC) $(CFLAGS) $(HEADER) -L $(LIBFT) -lft -L $(LIBGNL) -lgnl $(addprefix $(SRC_DIR),$(PS)) $(OBJS) -o $(NAME)

# test: $(OBJS) $(addprefix $(TEST_DIR),$(TEST)) libft libgnl
# 	$(CC) $(CFLAGS) $(HEADER) -L $(LIBFT) -lft -L $(LIBGNL) -lgnl $(addprefix $(TEST_DIR),$(TEST)) $(OBJS) -o test

bonus: $(addprefix $(SRC_DIR),$(BONUS)) $(OBJS) $(BONUS_OBJS) libft libgnl
	$(CC) $(CFLAGS) $(HEADER) -L $(LIBFT) -lft -L $(LIBGNL) -lgnl $(addprefix $(SRC_DIR),$(BONUS)) $(OBJS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(HEADER) -c $^ -o $@

# $(OBJ_PRINTER): $(SRCS_PRINTER)
# 	@$(CC) $(CFLAGS) $(HEADER) -c $^ -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	@make fclean -C ./lib/LIBFT/
	@make fclean -C ./lib/GNL/

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
# rm -f test

re: fclean all

libft:
	@make -C ./lib/Libft/

libgnl:
	@make -C ./lib/GNL/

.PHONY: all clean fclean re
