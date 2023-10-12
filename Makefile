NAME = push_swap
BONUS = checker

CC = cc
FLAGS = -Wall -Werror -Wextra -g3 -O3

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

SRC_DIR = ./src/
SRC =	$(SRC_DIR)push_swap.c		\
		$(SRC_DIR)swap.c			\
		$(SRC_DIR)rotate.c			\
		$(SRC_DIR)reverse_rotate.c	\
		$(SRC_DIR)push.c			\
		$(SRC_DIR)check.c			\
		$(SRC_DIR)sort_3.c			\
		$(SRC_DIR)sort_5.c			\
		$(SRC_DIR)sort_large.c		\
		$(SRC_DIR)sort_large_to_a.c	\
		$(SRC_DIR)error.c			\
		$(SRC_DIR)set_index.c		\
		$(SRC_DIR)lst_create.c		\
		$(SRC_DIR)find.c			\
		$(SRC_DIR)find2.c			\
		$(SRC_DIR)set.c

BONUS_DIR = ./bonus/
BONUS_SRC = $(BONUS_DIR)checker.c		\
			$(SRC_DIR)swap.c			\
			$(SRC_DIR)rotate.c			\
			$(SRC_DIR)reverse_rotate.c	\
			$(SRC_DIR)push.c			\
			$(SRC_DIR)lst_create.c		\
			$(SRC_DIR)check.c			\
			$(SRC_DIR)error.c

LIBS = -Llibft -lft

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) $(LIBS) -o $(BONUS)

$(LIBFT):
	@echo Creating Libft.
	@make -C libft
	@echo Libft done.

%.o: %.c
	$(CC) $(FLAGS) -I. -I./includes/ -c $< -o $@

clean:
	@make -C libft clean
	rm -rf $(OBJ)
	rm -rf $(BONUS_OBJ)
	
fclean: clean
	@make -C libft fclean
	rm -rf push_swap
	rm -rf checker	

re: fclean all

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./push_swap $(arg)

.PHONY: all clean fclean re bonus