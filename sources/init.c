#include "libft.h"
#include "push_swap.h"

static void init_stack_a(t_sort *sort, char **args);
static void update_index(t_stack *stack);

/*
 * Allocates and initializes the t_sort structure.
 * - Parses arguments and fills stack_a.
 * - Frees the argument array after processing.
 * - Assigns index values to each element in stack_a based on their order.
 * On failure, prints an error to the standart error and exits the program.
 */
t_sort *init_sort_struct(char **args)
{
    t_sort *sort;

    sort = ft_calloc(1, sizeof(t_sort));
    if (!sort)
    {
        free_2d_char_array(args);
        shut_program_error(sort, "Alloc error on init_sort_struct");
    }
    init_stack_a(sort, args);
    free_2d_char_array(args);
    update_index(sort->stack_a);
    return (sort);
}

/*
 * Populates stack_a using the provided arguments.
 * Each argument is converted and pushed to the stack using stack_a_update.
 */
static void init_stack_a(t_sort *sort, char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        stack_a_update(sort, args, args[i]);
        i++;
    }
}

/*
 * Assigns an index to each node in stack_a based on its value.
 * The index represents the number of elements with a smaller value.
 * This is used later for efficient sorting logic.
 */
static void update_index(t_stack *stack)
{
    t_stack *outer;
    t_stack *inner;
    int index;

    outer = stack;
    while (outer)
    {
        index = 0;
        inner = stack;
        while (inner)
        {
            if (inner->value < outer->value)
                index++;
            inner = inner->next;
        }
        outer->index = index;
        outer = outer->next;
    }
}
