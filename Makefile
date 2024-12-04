NAME = push_swap

SRCS = main.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibs/my_libft -Ilibs/my_printf

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libs/my_libft
	${MAKE} -C ./libs/my_printf
	${CC} ${CFLAGS} ${OBJS} ./libs/my_libft/libft.a ./libs/my_printf/libftprintf.a -o ${NAME}

clean: 
	${MAKE} -C ./libs/my_libft fclean
	${MAKE} -C ./libs/my_printf fclean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re