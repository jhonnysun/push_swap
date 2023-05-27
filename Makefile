NAME = push_swap

VERBOSE := 0

CC = gcc #-fsanitize=address

FLAGS = -Wall -Wextra -g #-Werror 

SRC =	main.c \
		ops_rot.c \
		ops.c \
		list_init.c \
		create_array.c \
		itoa_atoi.c \
		checkargs.c \
		utils.c \
		utils2.c \
		chuncks.c \
		sort_x.c \
		push_optimize.c \
		debugprints.c

OBJ_DIR := objs

OBJS := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

.PHONY: all clean fclean re

COLORS := 42 44 45 46 41 40

COUNT := 0

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(eval COLOR := $(shell echo "$(COLORS)" | cut -d' ' -f$(shell expr $(COUNT) % 6 + 1)))
	@echo "\033[$(COLOR)mCompiling $<...\033[0m"
	@$(eval COUNT := $(shell expr $(COUNT) + 1))
	@$(CC) -c -DVERBOSE=$(VERBOSE) $(FLAGS) -Iinclude $< -o $@

$(OBJ_DIR):
	@echo "\033[34m@@@@@@@@@@@@@@@@@@@@@@@@@@@@  ---------->   Creating objects... (in dir $(OBJ_DIR)/)\033[0m"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "\033[33mRemoving object files & directory...\033[0m"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[33mRemoving executable...\033[0m"
	@rm -f $(NAME)

re: fclean all