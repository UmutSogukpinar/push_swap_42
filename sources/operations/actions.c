#include "stdlib.h"
#include "push_swap.h"

/*
 * Pushes the top element from the source stack to the top of the target stack.
 * If the source stack is empty, no operation is performed.
 */
void	push(t_stack **source, t_stack **target)
{
	t_stack	*source_head;
	t_stack	*new_head;

	if (!(source && *source))
		return ;
	source_head = *source;
	new_head = (*source)->next;
	*source = new_head;
	source_head->next = NULL;
	stack_add_front(target, source_head);
}

/*
 * Swaps the first two elements of the given stack.
 * If the stack has fewer than two elements, no operation is performed.
 */
void	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = first_node -> next;
	first_node -> next = second_node -> next;
	second_node -> next = first_node;
	*stack = second_node;
}

/*
 * Rotates the given stack upwards.
 * The first element becomes the last one.
 */
void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	if (stack_size(*stack) <= 1)
		return ;
	first_node = *stack;
	second_node = first_node -> next;
	last_node = *stack;
	while (last_node -> next)
		last_node = last_node -> next;
	*stack = second_node;
	last_node -> next = first_node;
	first_node -> next = NULL;
}

/*
 * Rotates the given stack downwards.
 * The last element becomes the first one.
 * If the stack has only two elements, it simply performs a rotate.
 */

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*scnd_to_last_node;

	if (stack_size(*stack) <= 1)
		return ;
	if (stack_size(*stack) == 2)
	{
		rotate(stack);
		return ;
	}
	scnd_to_last_node = *stack;
	while (scnd_to_last_node -> next -> next)
		scnd_to_last_node = scnd_to_last_node -> next;
	last_node = scnd_to_last_node -> next;
	last_node -> next = *stack;
	scnd_to_last_node -> next = NULL;
	*stack = last_node;
}
