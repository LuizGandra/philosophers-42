NAME := philosophers

CC := clang
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDES_DIR := include
INCLUDES := -I$(INCLUDES_DIR)

HEADERS := $(INCLUDES_DIR)/philosophers.h $(INCLUDES_DIR)/errors.h

SRC_DIR := src
SRCS := \
	main.c \
	validation.c \
	handle_errors.c \
	init.c \
	global.c \
	utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR := build
OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

VALGRIND := valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

GDB := gdb
GDB_FLAGS := -tui -args

all: $(MLX) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

vg: all
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME) $(MAP)

gdb: all
	$(GDB) $(GDB_FLAGS) ./$(NAME) $(MAP)

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all bonus clean fclean re vg norm