#include "push_swap.h"

t_bool check_duplicates(t_sort *sort)
{
    t_stack *ptr1 = sort->stack_a;
    t_stack *ptr2;

    while (ptr1)
    {
        ptr2 = ptr1->next;
        while (ptr2)
        {
            if (ptr1->value == ptr2->value)
                return (FALSE);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return (TRUE);
}
