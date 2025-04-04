#include "push_swap.h"

void    sort_main(t_sort *sort)
{
    if (stack_size(sort->stack_a) == 2)
        sort_2_elements(sort, 1);
    else if (stack_size(sort->stack_a) == 3)
        sort_3_elements_asc(sort);
    else if (stack_size(sort->stack_a) >= 4)
        sort_deafult(sort);
}

t_bool	is_sorted(t_stack *stack)
{
    if (!stack)
        return (FALSE);
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (FALSE);
        stack = stack->next;
    }
    return (TRUE);
}

void    sort_deafult
