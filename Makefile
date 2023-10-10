NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -g3 -O3
OBJ = $(SRC:.c=.o)

SRC =	push_swap.c		\
		swap.c			\
		rotate.c		\
		reverse_rotate.c\
		push.c			\
		check.c			\
		sort_3.c		\
		sort_5.c		\
		sort_large.c	\
		error.c			\
		set_index.c		\
		lst_create.c	\
		find.c			\
		find2.c			\
		set.c

LIBS = -Llibft -lft

LIBFT = libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	@echo Creating libft.
	@make -C libft
	@echo Libft done.

%.o: %.c
	$(CC) $(CC_FLAGS) -O3 -c $< -o $@

clean:
	rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	rm -rf push_swap
	@make -C libft fclean

re: fclean all

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./push_swap $(arg)

.PHONY: all clean fclean re