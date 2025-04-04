#include "push_swap.h"
#include "operations.h"

static void sorting_setup(t_sort *sort);

void    sort_main(t_sort *sort)
{
    if (stack_size(sort->stack_a) == 2)
        sort_2_elements(sort, 1);
    else if (stack_size(sort->stack_a) == 3)
        sort_3_elements_asc(sort);
    else if (stack_size(sort->stack_a) >= 4)
        sort_deafult(sort);
}

void    sort_deafult(t_sort *sort)
{
    sorting_setup(sort);
    while (stack_size(sort->stack_a) > 3 && !is_partly_sorted(sort->stack_a))
    {
        
    }
}

static void sorting_setup(t_sort *sort)
{
    push_b(sort);
    push_b(sort);
    sort_2_elements(sort, 2);
}
