NAME = push_swap
TEST = test.c
BONUS_NAME = checker
BONUS = checker.c
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
		operations_utils.c \
		ps_initializer.c \
		ps_free.c \
		stack_status.c \
		indexer.c \
		small_nums_sorter.c \
		small_nums_sorter_utils.c \
		partitioner.c \
		large_nums_sorter.c \
		operations_counter.c \
		commands_selector.c \
		command.c \
		stack_printer.c
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

# $(OBJS): $(SRCS)
# 	$(CC) $(CFLAGS) $(HEADER) -L$(LIBFT) -lft -L$(LIBGNL) -lgnl -c $(SRCS)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	@make fclean -C ./lib/LIBFT/
	@make fclean -C ./lib/GNL/

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f test

re: fclean all

libft:
	@make -C ./lib/Libft/

libgnl:
	@make -C ./lib/GNL/

.PHONY: all clean fclean re
