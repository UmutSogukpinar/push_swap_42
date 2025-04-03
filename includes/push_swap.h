#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483648

#define SPACE_S " "
#define SPACE_C ' '

typedef enum e_bool
{
	FALSE,
	TRUE
} t_bool;

typedef struct s_way
{
	int pa;
	int pb;
	int sa;
	int sb;
	int ss;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;

} t_way;

typedef struct s_stack
{
	int value;
	struct s_stack *next;

} t_stack;

typedef struct s_sort
{
	t_list *stack_a;
	t_list *stack_b;
	t_way *way;

} t_sort;


t_bool	are_args_proper(char **args);
char **modify_args(int argc, char **args);
void    shut_program_error(char *message);

#endif