NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
OBJ = $(SRC:.c=.o)

SRC =	push_swap.c	\
		move.c		

LIBS = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -O3 -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf push_swap

re: fclean all

.PHONY: all clean fclean re