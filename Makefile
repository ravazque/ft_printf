
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, ft_printf.c ft_printf_char.c ft_printf_hex.c ft_printf_number.c ft_printf_ptr.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
