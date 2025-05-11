#include "unistd.h"
#include "libft.h"
#include "actions.h"

void	swap_a(t_sort *main)
{
	swap(&(main->stack_a));
	ft_putendl_fd(SA, STDOUT_FILENO);
}

void	swap_b(t_sort *main)
{
	swap(&(main->stack_b));
	ft_putendl_fd(SB, STDOUT_FILENO);
}

void	swap_both(t_sort *main)
{
	swap(&(main->stack_a));
	swap(&(main->stack_b));
	ft_putendl_fd(SS, STDOUT_FILENO);
}
