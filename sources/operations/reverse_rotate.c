#include "unistd.h"
#include "libft.h"
#include "actions.h"

void	reverse_rotate_a(t_sort *main)
{
	reverse_rotate(&(main->stack_a));
	ft_putendl_fd(RRA, STDOUT_FILENO);
}

void	reverse_rotate_b(t_sort *main)
{
	reverse_rotate(&(main->stack_b));
	ft_putendl_fd(RRB, STDOUT_FILENO);
}

void	reverse_rotate_both(t_sort *main)
{
	reverse_rotate(&(main->stack_a));
	reverse_rotate(&(main->stack_b));
	ft_putendl_fd(RRR, STDOUT_FILENO);
}
