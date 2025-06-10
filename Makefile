NAME := philosophers

CC := clang
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDES_DIR := include
LIBFT := lib/libft
LIBS := \
	-L$(LIBFT) -lft
INCLUDES := -I/usr/$(INCLUDES_DIR) -I$(INCLUDES_DIR) \
	-I$(LIBFT)/$(INCLUDES_DIR) -I$(LIBFT)/ft_printf/$(INCLUDES_DIR)

HEADERS := $(INCLUDES_DIR)/philosophers.h

SRC_DIR := src
SRCS := \
	main.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR := build
OBJECTS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

VALGRIND := valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

GDB := gdb
GDB_FLAGS := -tui -args

all: $(MLX) $(LIBFT) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

vg: all
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME) $(MAP)

gdb: all
	$(GDB) $(GDB_FLAGS) ./$(NAME) $(MAP)

norm:
	norminette -R CheckForbiddenSourceHeader

.PHONY: all bonus $(LIBFT) clean fclean re vg norm