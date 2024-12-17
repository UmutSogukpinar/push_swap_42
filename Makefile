NAME = push_swap

ACT_DIR = srcs/actions
CONT_DIR = srcs/controls
OPT_DIR = srcs/operations
SORT_DIR = srcs/sorting
LIB_DIR = ./libs

SRCS = main.c \
		${CONT_DIR}/is_number.c \
		${ACT_DIR}/actions.c \
		${SORT_DIR}/sort_small.c \
		${SORT_DIR}/sort.c \
		${OPT_DIR}/swap.c

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
	${MAKE} -C ${LIB_DIR}/my_libft clean
	${MAKE} -C ${LIB_DIR}/my_printf clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} -C ${LIB_DIR}/my_libft fclean
	${MAKE} -C ${LIB_DIR}/my_printf fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re