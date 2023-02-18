NAME = push_swap
TEST = test.c
CC = gcc
CFLAGS =  -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g3
TEST_DIR = ./spec/
SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRCS = check_file.c\
OBJS = $(SRC:%.c=$(OBJ_DIR)%.o)
HEADER = -I ./include
LIBFT = "./lib/Libft/"
LIBGNL = "./lib/GNL/"

all: $(NAME)

test: $(OBJS) $(addprefix $(TEST_DIR),$(TEST)) libft
	$(CC) $(CFLAGS) $(HEADER) -L$(LIBFT) -lft $(addprefix $(TEST_DIR),$(TEST)) $(OBJS) -o test

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $(CFLAGS) $(HEADER) $^ -o $@

clean:
	rm -f $(OBJS)
	@make fclean -C ./lib/LIBFT/

fclean:
	rm -f test

re:
	fclean all

libft:
	@make -C ./lib/Libft/

.PHONY: all clean fclean re
