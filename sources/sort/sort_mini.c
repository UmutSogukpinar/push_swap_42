#include "operations.h"

static void    sort_2_elements_asc(t_sort *sort);
static void    sort_2_elements_desc(t_sort *sort);

/*
 * Contains specialized sorting routines for small stacks.
 *
 * - sort_3_elements_asc: Sorts exactly 3 elements in ascending order in stack_a.
 * - sort_2_elements: Dispatcher for 2-element sorting, ascending or descending.
 * - sort_2_elements_asc: Sorts 2 elements in ascending order in stack_a.
 * - sort_2_elements_desc: Sorts 2 elements in descending order in stack_b.
 *
 * These functions are used to handle base cases in the push_swap algorithm.
 */

void    sort_3_elements_asc(t_sort *sort)
{
    t_stack *stack_a;

    if (!sort)
        return ;
    stack_a = sort->stack_a;
    int first = stack_a->value;
    int second = stack_a->next->value;
    int third = stack_a->next->next->value;
    if (first > second && second < third && first < third)
        swap_a(sort);
    else if (first > second && second > third)
    {
        swap_a(sort);
        reverse_rotate_a(sort);
    }
    else if (first > second && second < third && first > third)
        rotate_a(sort);
    else if (first < second && second > third && first < third)
    {
        swap_a(sort);
        rotate_a(sort);
    }
    else if (first < second && second > third && first > third)
        reverse_rotate_a(sort);
}


void sort_2_elements(t_sort *sort, int mode)
{
    if (!sort)
        return ;
    if (mode == 1)
        sort_2_elements_asc(sort);
    else if (mode == 2)
        sort_2_elements_desc(sort);
}

static void    sort_2_elements_asc(t_sort *sort)
{
    t_stack *sample;

    if (!sort)
        return ;
    sample = sort->stack_a;
    if (!sample || !sample->next)
        return ;
    if (sample->value > sample->next->value)
        swap_a(sort);
}

static void    sort_2_elements_desc(t_sort *sort)
{
    t_stack *sample;

    if (!sort)
        return ;
    sample = sort->stack_b;
    if (!sample || !sample->next)
        return ;
    if (sample->value < sample->next->value)
        swap_b(sort);
}
