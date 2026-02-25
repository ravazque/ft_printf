
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
OBJ_DIR = objects

SRC = $(addprefix $(SRC_DIR)/, ft_printf.c buffer.c print_char.c \
								print_number.c print_hex.c print_ptr.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRC = $(addprefix $(SRC_DIR)/, ft_printf_bonus.c buffer_bonus.c \
								utils_bonus.c flags_bonus.c \
								format_helpers_bonus.c print_char_bonus.c \
								print_number_bonus.c print_unsigned_bonus.c \
								print_hex_bonus.c print_ptr_bonus.c)
BONUS_OBJ = $(BONUS_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	rm -rf .bonus

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: .bonus

.bonus: $(BONUS_OBJ)
	$(RM) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJ)
	touch .bonus | echo -n "file to know which part of the compilation can continue to be prevented from relinking" >> .bonus

clean:
	$(RM) -r $(OBJ_DIR) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
