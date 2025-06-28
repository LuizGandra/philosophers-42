NAME := philosophers

CC := clang
CFLAGS := -Wall -Werror -Wextra
RM := rm -rf

INCLUDE_DIR := include
INCLUDES := -I$(INCLUDE_DIR)

HEADERS := philosophers.h errors.h ft_calloc.h mutex.h
HEADERS := $(addprefix $(INCLUDE_DIR)/, $(HEADERS))

SRC_DIR := src
LIB_DIR := lib
SRCS := \
	main.c \
	errors.c \
	global.c \
	init.c \
	print.c \
	states.c \
	tasks.c \
	time.c \
	utils.c \
	validation.c \
	watch.c \
	$(LIB_DIR)/ft_calloc.c \
	$(LIB_DIR)/mutex.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

BUILD_DIR := build
OBJECTS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

VALGRIND := valgrind
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

GDB := gdb
GDB_FLAGS := -tui -args

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ -g3 -O0

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -g3 -O0

clean:
	$(RM) $(BUILD_DIR)

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