#include "structures.h"
#include "libft.h"

static void free_push_swap(t_sort *sort);
static void	stack_clear(t_stack **stack);

void    shut_program_error(t_sort *sort, char *message)
{
    if (message)
        ft_putendl_fd(message, 2);
    free_push_swap(sort);
    exit(EXIT_FAILURE);
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
    // TODO: Implement Stack free function for stack_a and stack_b
    // TODO: Implement free function for way struct
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

