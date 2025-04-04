#include "libft.h"
#include "push_swap.h"

static t_stack	*create_node(char *value);
static void	stack_add_back(t_stack **stack, t_stack *new_stack);

/*
 * Adds a new node to stack_a in the main sort structure.
 * If memory allocation fails during node creation, prints an error and exits.
 */
void	stack_a_update(t_sort *main, char **args, char *value)
{
	t_stack	*new;

	new = create_node(value);
	if (!new)
	{
		free_2d_char_array(args);
		shut_program_error(main, NULL);
	}
	stack_add_back(&(main -> stack_a), new);
}

/*
 * Adds a new node to the front of the given stack.
 * Used for stack operations that require pushing elements to the top.
 */
void	stack_add_front(t_stack **stack, t_stack *new_stack)
{
	if (!stack || !new_stack)
		return ;
	new_stack -> next = *stack;
	*stack = new_stack;
}

/*
 * Returns the number of elements (nodes) in the given stack.
 */
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
}

/*
 * Adds a new node to the end of the given stack.
 * If the stack is empty, the new node becomes the head.
 */
static void	stack_add_back(t_stack **stack, t_stack *new_stack)
{
	t_stack	*temp;

	if (!stack | !new_stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new_stack;
		return ;
	}
	temp = *stack;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new_stack;
}

/*
 * Creates a new stack node from the given string value.
 * Converts the string to an integer, sets default index to -1.
 * Returns NULL if memory allocation fails.
 */
static t_stack	*create_node(char *value)
{
    t_stack	*node;

    node = ft_calloc(1, sizeof(t_stack));
    if (!node)
	{
		ft_putendl_fd("Error: Memory allocation failed on create_node()", 2);
        return (NULL);
	}
    node -> value = ft_atoi(value);
    node -> next = NULL;
    node -> index = -1;
    return (node);
}
