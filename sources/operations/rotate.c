#include "unistd.h"
#include "libft.h"
#include "actions.h"

void	rotate_a(t_sort *main)
{
	rotate(&(main->stack_a));
	ft_putendl_fd(RA, STDOUT_FILENO);
}

void	rotate_b(t_sort *main)
{
	rotate(&(main->stack_b));
	ft_putendl_fd(RB, STDOUT_FILENO);
}

void	rotate_both(t_sort *main)
{
	rotate(&(main->stack_a));
	rotate(&(main->stack_b));
	ft_putendl_fd(RR, STDOUT_FILENO);
}
