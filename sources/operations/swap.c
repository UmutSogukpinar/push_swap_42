#include "libft.h"
#include "actions.h"

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
