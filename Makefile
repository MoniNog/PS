NAME = push_swap
CC = gcc
CFLAGS =  -Wall -Werror -Wextra -g3 -fsanitize=address -I./lib/libft
# CFLAGS =  -Wall -Werror -Wextra -I./lib/libft
LIBFT_PATH = ./lib/libft
LIBFT = -L$(LIBFT_PATH) -lft

SRC = src/main.c src/fun/push.c src/fun/reverse_rotate.c src/fun/rotate.c\
	src/fun/swap.c src/fun/utils_functions.c src/memory_management.c
OBJS = $(SRC:.c=.o)
HEADERS = -Iincludes

all: $(NAME)

$(NAME): $(OBJS) libft.a
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIBFT)

libft.a:
	@make -C $(LIBFT_PATH) --silent

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean --silent
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean --silent
	@rm -f $(NAME)

re: fclean all
