#include "libft.h"
#include "actions.h"

/*
 * Executes rotate operations and prints the command.
 * - rotate_a: stack_a ↑ ("ra")
 * - rotate_b: stack_b ↑ ("rb")
 * - rotate_both: both stacks ↑ ("rr")
 */

void	rotate_a(t_sort *main)
{
	rotate(&(main -> stack_a));
    ft_putendl_fd("ra", 1);
}

void	rotate_b(t_sort *main)
{
	rotate(&(main -> stack_b));
    ft_putendl_fd("rb", 1);
}

void	rotate_both(t_sort *main)
{
	rotate(&(main -> stack_a));
	rotate(&(main -> stack_b));
    ft_putendl_fd("rr", 1);
}
