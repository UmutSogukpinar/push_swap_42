#ifndef CUSTOM_BOOL_H
#define CUSTOM_BOOL_H

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
	int index;
	struct s_stack *next;

} t_stack;

typedef struct s_sort
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_way *way;

} t_sort;

#endif