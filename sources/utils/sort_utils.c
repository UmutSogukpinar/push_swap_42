#include "structures.h"

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

t_bool  is_partly_sorted(t_stack *stack)
{
    t_stack *head;
    int breaks;

    if (!stack || !stack->next)
        return (FALSE);
    breaks = 0;
    head = stack;
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            breaks++;
        stack = stack->next;
    }
    if (stack->value > head->value)
        breaks++;
    return (breaks <= 1);
}

