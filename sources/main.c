#include "stdlib.h"
#include "push_swap.h"
// ! will be removed
#include <stdio.h>

// ! will be removed
void print_sort(t_sort *sort);

int main(int argc, char **args)
{
    t_sort *sort;
    char **modified_args;

    if (argc < 2)
        return (EXIT_SUCCESS);
    if (are_args_nul(argc, args))
        return (ERROR_EXIT_CODE);
    modified_args = modify_args(argc, args);
    if (!are_args_proper(modified_args))
    {
        free_2d_char_array(modified_args);
        return (ERROR_EXIT_CODE);
    }
    sort = init_sort_struct(modified_args);
    if (is_sorted(sort->stack_a))
        return (shut_program_success(sort));
    else
        sort_main(sort);
    shut_program_success(sort);
    return (EXIT_SUCCESS);
}

void print_way(t_way *way)
{
    if (!way)
    {
        printf("way: (null)\n");
        return;
    }

    printf("Way:\n");
    printf("  pa: %d\n", way->pa);
    printf("  pb: %d\n", way->pb);
    printf("  sa: %d\n", way->sa);
    printf("  sb: %d\n", way->sb);
    printf("  ss: %d\n", way->ss);
    printf("  ra: %d\n", way->ra);
    printf("  rb: %d\n", way->rb);
    printf("  rr: %d\n", way->rr);
    printf("  rra: %d\n", way->rra);
    printf("  rrb: %d\n", way->rrb);
    printf("  rrr: %d\n", way->rrr);
}

void print_stack(const char *name, t_stack *stack)
{
    printf("%s:\n", name);
    if (!stack)
    {
        printf("  (empty)\n");
        return;
    }

    int i = 0;
    while (stack)
    {
        printf("  [%d] value: %d, index: %d\n", i, stack->value, stack->index);
        stack = stack->next;
        i++;
    }
}

void print_sort(t_sort *sort)
{
    if (!sort)
    {
        printf("sort: (null)\n");
        return;
    }

    printf("=== t_sort ===\n");
    print_stack("stack_a", sort->stack_a);
    print_stack("stack_b", sort->stack_b);
    print_way(sort->way);
    printf("================\n");
}