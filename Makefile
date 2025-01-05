NAME = push_swap

SRCS_DIR = ./srcs
ACT_DIR = srcs/actions
UTIL_DIR = srcs/utils
OPT_DIR = srcs/operations
SORT_DIR = srcs/sorting
LIB_DIR = ./libs

SRCS = 	$(SRCS_DIR)/main.c \
		$(SRCS_DIR)/exit.c \
		${ACT_DIR}/actions.c \
		${UTIL_DIR}/is_number.c \
		${UTIL_DIR}/find_index.c \
		${UTIL_DIR}/get_tail.c \
		${UTIL_DIR}/init.c \
		${OPT_DIR}/swap.c \
		${OPT_DIR}/push.c \
		${OPT_DIR}/rotate.c \
		${OPT_DIR}/reverse_rotate.c \
		${SORT_DIR}/sort.c \
		${SORT_DIR}/sort_default.c \
		${SORT_DIR}/find_way.c \
		${SORT_DIR}/resend.c \
		${SORT_DIR}/resend_utils.c \
		${SORT_DIR}/sort_utils.c \
		${SORT_DIR}/is_sorted.c \
		${SORT_DIR}/sort_mini.c \
		${SORT_DIR}/sort_three_helper.c \
		${SORT_DIR}/sort_three_reverse_helper.c \

OBJS = ${SRCS:.c=.o}

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
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

run:
	./${NAME} ${ARGS}

.PHONY: all clean fclean re run
