
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c\
	ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c ft_atol.c ft_arrlen.c ft_safe_free.c\
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
	ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
	ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_abs.c ft_swap.c\
	get_next_line.c get_next_line_utils.c\
	ft_printf/ft_printf.c ft_printf/num_printers.c\
	ft_printf/handlers.c ft_printf/checkers.c\
	ft_dbl_lstadd_back.c ft_dbl_lstadd_front.c ft_dbl_lstclear.c\
	ft_dbl_lstnew.c ft_dbl_lstdelone.c ft_dbl_lstsize.c\
	
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
NAME = libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf libft.a	

re: fclean all