#include "libft.h"
#include "structures.h"

static void free_push_swap(t_sort *sort);
static void	stack_clear(t_stack **stack);

/*
 * Handles shutdown of the push_swap program.
 *
 * Provides utility functions to free all dynamically allocated memory
 * associated with the t_sort structure, including both stacks and sorting paths.
 *
 * - shut_program_error: Prints an error message (if provided), frees memory (if provided), 
 *      and exits with code 255.
 * - shut_program_success: Frees all allocated memory in main struct,
 *      and returns EXIT_SUCCESS.
 * - free_push_swap: Internal helper to clean up the t_sort struct.
 * - stack_clear: Frees all nodes in a stack (linked list).
 */

void    shut_program_error(t_sort *sort, char *message)
{
    if (message)
        ft_putendl_fd(message, 2);
    free_push_swap(sort);
    exit(255);
}

int    shut_program_success(t_sort *sort)
{
    free_push_swap(sort);
    return (EXIT_SUCCESS);
}

static void free_push_swap(t_sort *sort)
{
    if (!sort)
        return ;
    if (sort->stack_a)
        stack_clear(&sort->stack_a);
    if (sort->stack_b)
        stack_clear(&sort->stack_b);
    free(sort->way);
    free(sort);
}

static void	stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)-> next;
		free(temp);
	}
}
