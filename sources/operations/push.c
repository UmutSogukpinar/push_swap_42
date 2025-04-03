#include "actions.h"
#include "libft.h"

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