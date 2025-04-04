NAME = push_swap
BONUS_NAME = checker

LIB_DIR = libs/libft
SRCS_DIR = sources
STACK_DIR = $(SRCS_DIR)/stack
SORT_DIR = $(SRCS_DIR)/sort
OPERATIONS_DIR = $(SRCS_DIR)/operations
UTILS_DIR = $(SRCS_DIR)/utils
BONUS_DIR = bonus
GNL_DIR = $(BONUS_DIR)/gnl
OBJ_DIR = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIB_DIR)
BONUS_CFLAGS = $(CFLAGS) -I$(GNL_DIR) -D BUFFER_SIZE=42
RM = rm -rf

# Colours
GREEN := \033[0;32m
RESET := \033[0m
BOLD := \033[1m

# Main sources
SOURCES =	$(SRCS_DIR)/main.c 					\
			$(SRCS_DIR)/init.c 					\
			$(SRCS_DIR)/shut.c 					\
			$(STACK_DIR)/stack.c 				\
			$(OPERATIONS_DIR)/actions.c			\
			$(OPERATIONS_DIR)/push.c			\
			$(OPERATIONS_DIR)/swap.c			\
			$(OPERATIONS_DIR)/rotate.c			\
			$(OPERATIONS_DIR)/reverse_rotate.c	\
			$(SORT_DIR)/sort.c					\
			$(SORT_DIR)/sort_mini.c				\
			$(SORT_DIR)/way.c					\
			$(SORT_DIR)/execute.c				\
			$(UTILS_DIR)/check_args.c			\
			$(UTILS_DIR)/arrange_args.c			\
			$(UTILS_DIR)/casual_utils.c			\
			$(UTILS_DIR)/position.c				\
			$(UTILS_DIR)/way_utils.c			\

# Bonus sources
BONUS_SOURCES =	$(BONUS_DIR)/checker_bonus.c		\
				$(GNL_DIR)/get_next_line.c			\
				$(GNL_DIR)/get_next_line_utils.c	\
				$(SRCS_DIR)/init.c					\
				$(SRCS_DIR)/shut.c					\
				$(STACK_DIR)/stack.c				\
				$(OPERATIONS_DIR)/actions.c			\
				$(OPERATIONS_DIR)/push.c			\
				$(OPERATIONS_DIR)/swap.c			\
				$(OPERATIONS_DIR)/rotate.c			\
				$(OPERATIONS_DIR)/reverse_rotate.c	\
				$(UTILS_DIR)/check_args.c			\
				$(UTILS_DIR)/arrange_args.c			\
				$(UTILS_DIR)/casual_utils.c			\

# Object files
OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SOURCES:.c=.o))

# Compile rule
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BOLD)🔨 Compiling: $(RESET) $(GREEN) $< $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIB_DIR) --silent
	@echo "$(GREEN)✅ Libft build complete!$(RESET)"
	@echo "$(BOLD)📦 Linking:$(RESET) $(GREEN)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -o $(NAME)
	@echo "$(GREEN)✅ Build completed successfully for user: $(shell whoami) $(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(MAKE) -C $(LIB_DIR) --silent
	@echo "$(GREEN)✅ Libft build complete!$(RESET)"
	@echo "$(BOLD)📦 Linking:$(RESET) $(GREEN)$(BONUS_NAME)$(RESET)"
	@$(CC) $(BONUS_CFLAGS) $(BONUS_OBJS) $(LIB_DIR)/libft.a -o $(BONUS_NAME)
	@echo "$(GREEN)✅ Bonus (checker) build complete for user: $(shell whoami) $(RESET)"

clean:
	@$(MAKE) -C $(LIB_DIR) fclean --silent
	@$(RM) $(OBJ_DIR)
	@echo "$(BOLD)🧹 Cleaned object files and libft.$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(BOLD)🧼 Full clean: removed binaries.$(RESET)"

re: fclean all

# Test targets
test2 test3 test5 test100 test500: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n $(subst test,,$@)))
	@echo -n "Status: " 
	@./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

valgrind: $(NAME)
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	valgrind ./push_swap $(ARG)

.PHONY: all clean fclean re bonus test2 test3 test5 test100 test500 valgrind
