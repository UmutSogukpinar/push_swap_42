NAME = push_swap

SRCS_DIR = ./srcs
SORT_DIR = ./srcs/sort
STACK_DIR = ./srcs/stack
ACT_DIR = ./srcs/actions
OPR_DIR = ./srcs/operations

LIB_DIR = ./libs
OBJ_DIR = ./objs

SOURCES =	$(SRCS_DIR)/main.c \
			$(SRCS_DIR)/shut.c \
			$(SRCS_DIR)/init.c \
			$(SRCS_DIR)/helpers.c \
			$(SRCS_DIR)/helpers_two.c \
			$(ACT_DIR)/actions.c \
			$(OPR_DIR)/push.c \
			$(OPR_DIR)/swap.c \
			$(OPR_DIR)/rotate.c \
			$(OPR_DIR)/reverse_rotate.c \
			$(STACK_DIR)/list_utils.c \
			$(STACK_DIR)/stack_utils.c \
			$(STACK_DIR)/stack_utils_two.c \
			$(STACK_DIR)/stack_display.c \
			$(SORT_DIR)/sort.c \
			$(SORT_DIR)/sort_mini.c \
			$(SORT_DIR)/is_sorted.c \
			$(SORT_DIR)/resend/optimum_resend.c \
			$(SORT_DIR)/resend/resend.c \
			$(SORT_DIR)/turk/sort_default.c \

OBJS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibs/my_libft -Ilibs/my_printf

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libs/my_printf
	${MAKE} -C ./libs/my_libft
	${CC} ${CFLAGS} ${OBJS} ${LIB_DIR}/my_printf/libftprintf.a ${LIB_DIR}/my_libft/libft.a  -o ${NAME}

clean: 
	${MAKE} -C ${LIB_DIR}/my_printf fclean
	${MAKE} -C ${LIB_DIR}/my_libft fclean
	${RM} ${OBJ_DIR}
	
fclean: clean
	${RM} ${NAME}

re: fclean all

${OBJ_DIR}:
	mkdir -p $(OBJ_DIR) $(OBJ_DIR)/srcs $(OBJ_DIR)/srcs/sort $(OBJ_DIR)/srcs/stack $(OBJ_DIR)/srcs/actions $(OBJ_DIR)/srcs/operations

${OBJS}: ${OBJ_DIR}/%.o : %.c | ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@

.PHONY: all clean fclean re run
