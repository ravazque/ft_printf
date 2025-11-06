
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, ft_printf.c buffer.c utils.c flags.c \
								format_helpers.c print_char.c print_number.c \
								print_hex.c print_ptr.c)
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
