NAME = push_swap
CC = gcc
# CFLAGS =  -Werror -Wall -Wextra -g3 -fsanitize=address -I./lib/libft
CFLAGS =  -Werror -Wall -Wextra -I./lib/libft
LIBFT_PATH = ./lib/libft
LIBFT = -L$(LIBFT_PATH) -lft

SRC = src/main.c
OBJS = $(SRC:.c=.o)
HEADERS = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIBFT)

@$(OBJS): %.o : %.c
	@$(CC) $(CFLAGS) $(HEADERS)-I$(LIBFT_PATH) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
