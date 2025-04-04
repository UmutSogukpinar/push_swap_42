#include "libft.h"
#include "actions.h"

/*
 * Executes push operations and prints the corresponding command.
 * - push_a: stack_b → stack_a ("pa")
 * - push_b: stack_a → stack_b ("pb")
 */

void	push_a(t_sort *main)
{
	push(&(main -> stack_b), &(main -> stack_a));
	ft_putendl_fd("pa", 1);
}

void	push_b(t_sort *main)
{
	push(&(main -> stack_a), &(main -> stack_b));
	ft_putendl_fd("pb", 1);
}
