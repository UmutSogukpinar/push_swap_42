#include "libft.h"
#include "actions.h"

/*
 * Executes swap operations and prints the command.
 * - swap_a: top two of stack_a ↔ ("sa")
 * - swap_b: top two of stack_b ↔ ("sb")
 * - swap_both: top two of both stacks ↔ ("ss")
 */

void	swap_a(t_sort *main)
{
	swap(&(main->stack_a));
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_sort *main)
{
	swap(&(main->stack_b));
	ft_putendl_fd("sb", 1);
}

void	swap_both(t_sort *main)
{
    swap(&(main->stack_a));
    swap(&(main->stack_b));
    ft_putendl_fd("ss", 1);
}
