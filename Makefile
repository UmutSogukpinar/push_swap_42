NAME = push_swap

ACT_DIR = srcs/actions
CONT_DIR = srcs/controls
OPT_DIR = srcs/operations
SORT_DIR = srcs/sorting
LIB_DIR = ./libs

SRCS = main.c \
		${ACT_DIR}/actions.c \
		${CONT_DIR}/is_number.c \
		${CONT_DIR}/find_index.c \
		${OPT_DIR}/swap.c \
		${OPT_DIR}/push.c \
		${OPT_DIR}/rotate.c \
		${OPT_DIR}/reverse_rotate.c \
		${SORT_DIR}/sort_mini.c \
		${SORT_DIR}/sort_three_helper.c \
		${SORT_DIR}/sort.c \
		${SORT_DIR}/is_sorted.c \
		${SORT_DIR}/sort_default.c \
		${SORT_DIR}/sort_three_reverse_helper.c \

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibs/my_libft -Ilibs/my_printf

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libs/my_libft
	${MAKE} -C ./libs/my_printf
	${CC} ${CFLAGS} ${OBJS} ${LIB_DIR}/my_libft/libft.a ${LIB_DIR}/my_printf/libftprintf.a -o ${NAME}

clean: 
	${MAKE} -C ${LIB_DIR}/my_libft fclean
	${MAKE} -C ${LIB_DIR}/my_printf fclean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re