#include "push_swap.h"

static void init_stack_a(t_sort *sort, char **args);

t_sort *init_sort_struct(char **args)
{
    t_sort *sort;

    sort = ft_calloc(1, sizeof(t_sort));
    if (!sort)
    {
        free(args);
        shut_program_error("Alloc error on init_sort_struct");
    }
    init_stack_a(sort, args);
}


// TODO: Implement the function to initialize stack_a
static void init_stack_a(t_sort *sort, char **args)
{
    int i;
}
