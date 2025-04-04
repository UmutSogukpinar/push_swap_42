#include "libft.h"
#include "actions.h"

/*
 * Executes reverse rotate operations and prints the command.
 * - reverse_rotate_a: stack_a ↓ ("rra")
 * - reverse_rotate_b: stack_b ↓ ("rrb")
 * - reverse_rotate_both: both stacks ↓ ("rrr")
 */

void	reverse_rotate_a(t_sort *main)
{
	reverse_rotate(&(main -> stack_a));
    ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(t_sort *main)
{
	reverse_rotate(&(main -> stack_b));
    ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_both(t_sort *main)
{
	reverse_rotate(&(main -> stack_a));
	reverse_rotate(&(main -> stack_b));
    ft_putendl_fd("rrr", 1);
}
