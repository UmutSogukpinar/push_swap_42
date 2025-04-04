#include "push_swap.h"

/*
 * Returns the position (0-based) of the node with the given index in the stack.
 * If not found, returns -1.
 */
int get_position(t_stack *stack, int index)
{
	int position = 0;

	while (stack)
	{
		if (stack->index == index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

/*
 * Returns the largest index in the stack that is smaller than the given index.
 * Used for insertion point calculation in A_TO_B mode.
 */
int get_biggest_smaller_index(t_stack *stack, int given_index)
{
	int max_index = -1;

	while (stack)
	{
		if (stack->index < given_index && stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

/*
 * Returns the smallest index in the stack that is greater than the given index.
 * Used for insertion point calculation in B_TO_A mode.
 */
int get_smallest_bigger_index(t_stack *stack, int given_index)
{
	int min_index;
    
    min_index = MAX_INT;
	while (stack)
	{
		if (stack->index > given_index && stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	if (min_index == MAX_INT)
		return (-1);
	return (min_index);
}

/*
 * Returns the highest index found in the given stack.
 */
int get_biggest_index(t_sort *main, t_stack *stack)
{
	int max_index;

	if (!stack)
		shut_program_error(main,
                "Error: Stack is empty in get_biggest_index()");
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

/*
 * Returns the lowest index found in the given stack.
 */
int get_smallest_index(t_sort *main, t_stack *stack)
{
	int min_index;

	if (!stack)
		shut_program_error(main,
                "Error: Stack is empty in get_smallest_index()");
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}
