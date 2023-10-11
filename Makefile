NAME = push_swap
BONUS = checker
CC = cc
FLAGS = -Wall -Werror -Wextra -g3 -O3
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

SRC =	push_swap.c			\
		swap.c				\
		rotate.c			\
		reverse_rotate.c	\
		push.c				\
		check.c				\
		sort_3.c			\
		sort_5.c			\
		sort_large.c		\
		sort_large_to_a.c	\
		error.c				\
		set_index.c			\
		lst_create.c		\
		find.c				\
		find2.c				\
		set.c

BONUS_SRC = ./checker_src/checker.c	\
			swap.c					\
			rotate.c				\
			reverse_rotate.c		\
			push.c					\
			lst_create.c			\
			check.c					\
			error.c

LIBS = -Llibft -lft

LIBFT = libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBS) -o $(BONUS)

$(LIBFT):
	@echo Creating Libft.
	@make -C libft
	@echo Libft done.

%.o: %.c
	$(CC) $(FLAGS) $(CC_FLAGS) -O3 -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)
	@make -C libft clean

fclean: clean
	rm -rf push_swap
	rm -rf checker
	@make -C libft fclean

re: fclean all

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./push_swap $(arg)

.PHONY: all clean fclean re bonus