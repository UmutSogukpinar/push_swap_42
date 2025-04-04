#ifndef CUSTOM_BOOL_H
#define CUSTOM_BOOL_H

/*
 * Simple boolean enum for the boolean statement.
 */
typedef enum e_bool
{
    FALSE,
    TRUE
} t_bool;

/*
 * Holds the number of operations required to move a specific element.
 * Each field corresponds to a stack operation (e.g., ra = rotate_a count).
 */
typedef struct s_way
{
	int pa;   // push_a
	int pb;   // push_b
	int sa;   // swap_a
	int sb;   // swap_b
	int ss;   // swap both
	int ra;   // rotate_a
	int rb;   // rotate_b
	int rr;   // rotate both
	int rra;  // reverse_rotate_a
	int rrb;  // reverse_rotate_b
	int rrr;  // reverse_rotate both
} t_way;

/*
 * Node of a stack (used for both stack_a and stack_b).
 * 'value' is the original number, 'index' is its sorted position.
 */
typedef struct s_stack
{
	int value;
	int index;
	struct s_stack *next;
} t_stack;

/*
 * Main structure holding both stacks and the current best move path (t_way).
 */
typedef struct s_sort
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_way *way;
} t_sort;

#endif