#include "libft.h"
#include "actions.h"

void	rotate_a(t_sort *main)
{
	rotate(&(main -> stack_a));
    ft_putendl_fd("ra", 1);
}

void	rotate_b(t_sort *main)
{
	rotate(&(main -> stack_b));
    ft_putendl_fd("rb", 1);
}

void	rotate_both(t_sort *main)
{
	rotate(&(main -> stack_a));
	rotate(&(main -> stack_b));
    ft_putendl_fd("rr", 1);
}