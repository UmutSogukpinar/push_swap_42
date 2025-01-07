NAME = push_swap

SRCS_DIR = ./srcs
STACK_DIR = ./srcs/stack

LIB_DIR = ./libs

SOURCES =	$(SRCS_DIR)/main.c \
			$(SRCS_DIR)/shut.c \
			$(SRCS_DIR)/init.c \
			$(STACK_DIR)/stack_utils.c \
			$(STACK_DIR)/stack_display.c \

OBJS = ${SOURCES:.c=.o}

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


.PHONY: all clean fclean re run
