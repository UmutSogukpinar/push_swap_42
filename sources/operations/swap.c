#include "actions.h"
#include "libft.h"

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
