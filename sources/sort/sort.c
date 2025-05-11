#include "operations.h"
#include "push_swap.h"

static void	sorting_setup(t_sort *sort);
static void	sort_default(t_sort *sort);
static void	final_sort(t_sort *sort);

void	sort_main(t_sort *sort)
{
	if (!sort)
		return ;
	if (stack_size(sort->stack_a) == 2)
		sort_2_elements(sort, 1);
	else if (stack_size(sort->stack_a) == 3)
		sort_3_elements_asc(sort);
	else if (stack_size(sort->stack_a) >= 4)
		sort_default(sort);
}

static void	sort_default(t_sort *sort)
{
	int	stack_a_size;

	sorting_setup(sort);
	stack_a_size = stack_size(sort->stack_a);
	while (stack_a_size > 3 && !is_partly_sorted(sort->stack_a))
	{
		create_way(sort, A_TO_B);
		execute_way(sort);
	}
	if (!is_partly_sorted(sort->stack_a))
		sort_main(sort);
	while (stack_size(sort->stack_b) > 0)
	{
		create_way(sort, B_TO_A);
		execute_way(sort);
	}
	if (!is_sorted(sort->stack_a))
		final_sort(sort);
}

static void	final_sort(t_sort *sort)
{
	t_stack	*stack;
	int		smallest_index;
	int		pos;
	int		size;
	int		i;

	stack = sort->stack_a;
	smallest_index = get_smallest_index(sort, stack);
	pos = get_position(stack, smallest_index);
	size = stack_size(stack);
	i = -1;
	if (pos <= size / 2)
	{
		while (++i < pos)
			rotate_a(sort);
	}
	else
	{
		while (++i < size - pos)
			reverse_rotate_a(sort);
	}
}

static void	sorting_setup(t_sort *sort)
{
	push_b(sort);
	push_b(sort);
	sort_2_elements(sort, 2);
}
