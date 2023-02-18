NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR),/get_next_line.c)\
	   $(addprefix $(SRC_DIR),/get_next_line_utils.c)
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = $(addprefix $(SRC_DIR),/get_next_line_bonus.c)\
		     $(addprefix $(SRC_DIR),/get_next_line_utils_bonus.c)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# $(addprefix $(SRC_DIR),$(OBJS)): $(SRCS)
# 	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BONUS) $(OBJS)
	ar rcs $(NAME) $(OBJS_BONUS) $(OBJS)

# $(addprefix $(SRC_DIR),$(OBJS_BONUS)): $(SRCS_BONUS)
# 	$(CC) $(CFLAGS) -c $(SRCS_BONUS)
