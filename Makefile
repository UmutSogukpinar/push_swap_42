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
			$(SORT_DIR)/update_way.c \
			$(SORT_DIR)/resend/optimum_resend.c \
			$(SORT_DIR)/resend/resend.c \
			$(SORT_DIR)/turk/sort_default.c \
			$(SORT_DIR)/turk/optimum.c \
			$(SORT_DIR)/turk/create_way.c \
			$(SORT_DIR)/execute/execute.c

OBJS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibs/my_libft -Ilibs/my_printf

RM = rm -rf

ARGS = 45 12 76 98 23 67 89 10 34 56 78 3 21 90 54 87 32 65 43 11 22 33 44 55 66 77 88 99 1 2 4 5 6 7 8 9 13 14 15 16 17 18 19 20 24 25 26 27 28 29 30 31 35 36 37 38 39 40 41 42 46 47 48 49 50 51 52 53 57 58 59 60 61 62 63 64 68 69 70 71 72 73 74 75 79 80 81 82 83 84 85 86 91 92 93 94 95 96 97 100

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

run: ${NAME}
	./${NAME} $(ARGS)

.PHONY: all clean fclean re run
