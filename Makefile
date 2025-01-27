NAME = push_swap
BONUS_NAME = checker

SRCS_DIR = ./srcs
SORT_DIR = ./srcs/sort
STACK_DIR = ./srcs/stack
OPR_DIR = ./srcs/operations
HELP_DIR = ./srcs/helpers

BONUS_DIR = ./bonus
GNL_DIR = ./bonus/get_next_line

LIB_DIR = ./libs

SOURCES =	$(SRCS_DIR)/main.c \
			$(SRCS_DIR)/shut.c \
			$(SRCS_DIR)/init.c \
			$(HELP_DIR)/helpers.c \
			$(HELP_DIR)/helpers_two.c \
			$(HELP_DIR)/helpers_three.c \
			$(HELP_DIR)/helpers_four.c \
			$(OPR_DIR)/actions.c \
			$(OPR_DIR)/push.c \
			$(OPR_DIR)/swap.c \
			$(OPR_DIR)/rotate.c \
			$(OPR_DIR)/reverse_rotate.c \
			$(STACK_DIR)/list_utils.c \
			$(STACK_DIR)/stack_utils.c \
			$(STACK_DIR)/stack_utils_two.c \
			$(SORT_DIR)/sort.c \
			$(SORT_DIR)/sort_mini.c \
			$(SORT_DIR)/is_sorted.c \
			$(SORT_DIR)/update_way.c \
			$(SORT_DIR)/resend/optimum_resend.c \
			$(SORT_DIR)/resend/resend.c \
			$(SORT_DIR)/turk/sort_default.c \
			$(SORT_DIR)/turk/optimum.c \
			$(SORT_DIR)/turk/create_way.c \
			$(SORT_DIR)/execute/execute.c \
			$(SORT_DIR)/execute/minimize_case.c \
			$(SORT_DIR)/execute/minimize_list.c \

BONUS = 	$(BONUS_DIR)/main_bonus.c \
			$(BONUS_DIR)/shut_bonus.c \
			$(BONUS_DIR)/check_bonus.c \
			$(BONUS_DIR)/execute_bonus.c \
			$(BONUS_DIR)/helper_bonus.c \
			$(BONUS_DIR)/helper_two_bonus.c \
			$(BONUS_DIR)/action_bonus.c \
			$(BONUS_DIR)/operation_bonus.c \
			$(BONUS_DIR)/operation_two_bonus.c \
			$(BONUS_DIR)/operation_three_bonus.c \
			$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c \


CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibs/libft -Ilibs/printf 
BONUS_FLAGS = -Wall -Wextra -Werror -Iincludes -Ilibs/libft -Ilibs/printf -Ibonus -Ibonus/get_next_line 

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB_DIR)/printf
	$(MAKE) -C $(LIB_DIR)/libft
	$(CC) $(CFLAGS) $(SOURCES) $(LIB_DIR)/printf/libftprintf.a $(LIB_DIR)/libft/libft.a -o $(NAME)

clean: 
	$(MAKE) -C $(LIB_DIR)/printf fclean
	$(MAKE) -C $(LIB_DIR)/libft fclean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: fclean all

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

valgrind:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					valgrind ./push_swap $(ARG)


bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(MAKE) -C ./libs/printf
	$(MAKE) -C ./libs/libft
	$(CC) $(BONUS_FLAGS) $(BONUS) $(LIB_DIR)/printf/libftprintf.a $(LIB_DIR)/libft/libft.a -o $(BONUS_NAME)

.PHONY: all clean fclean re run valgrind bonus test2 test3 test5 test100 test500 
