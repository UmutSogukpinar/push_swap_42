#include "stdlib.h"
#include "push_swap.h"

/*
 * Entry point of the push_swap program.
 * - Validates and preprocesses command-line arguments.
 * - Initializes the sorting structure and checks if the input is already sorted.
 * - If not sorted, executes the sorting algorithm.
 * - Frees all allocated memory before exiting.
 */
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
