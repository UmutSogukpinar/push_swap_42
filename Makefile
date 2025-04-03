NAME = push_swap

LIB_DIR = libs/libft
SRCS_DIR = sources
STACK_DIR = $(SRCS_DIR)/stack
OPERATIONS_DIR = $(SRCS_DIR)/operations
UTILS_DIR = $(SRCS_DIR)/utils

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(LIB_DIR)
RM = rm -rf

SOURCES =	$(SRCS_DIR)/main.c 					\
			$(SRCS_DIR)/init.c 					\
			$(SRCS_DIR)/shut.c 					\
			$(STACK_DIR)/stack.c 				\
			$(OPERATIONS_DIR)/actions.c			\
			$(OPERATIONS_DIR)/push.c			\
			$(OPERATIONS_DIR)/swap.c			\
			$(OPERATIONS_DIR)/rotate.c			\
			$(OPERATIONS_DIR)/reverse_rotate.c	\
			$(UTILS_DIR)/check_args.c			\
			$(UTILS_DIR)/arrange_args.c			\
			$(UTILS_DIR)/casual_utils.c			\


OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIB_DIR) --silent
	@$(CC) $(CFLAGS) $(SOURCES) $(LIB_DIR)/libft.a -o $(NAME)

clean: 
	@$(MAKE) -C $(LIB_DIR) fclean --silent
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

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

    


.PHONY: all clean fclean re
