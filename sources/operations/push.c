#include "unistd.h"
#include "libft.h"
#include "actions.h"

void	push_a(t_sort *main)
{
	push(&(main->stack_b), &(main->stack_a));
	ft_putendl_fd(PA, STDOUT_FILENO);
}

void	push_b(t_sort *main)
{
	push(&(main->stack_a), &(main->stack_b));
	ft_putendl_fd(PB, STDOUT_FILENO);
}
