#include "push_swap.h"

static void	minimize_way(t_way *way);
static void	fill_way_direct(t_way *temp_way, t_sort *main, int index);
static void	fill_way_reverse(t_way *temp_way, t_sort *main, int index);

void	fill_way(t_way *temp_way, t_sort *main, int index, int mode)
{
	if (mode == A_TO_B)
	{
		fill_way_direct(temp_way, main, index);
		temp_way->pb = 1;
	}
	else if (mode == B_TO_A)
	{
		fill_way_reverse(temp_way, main, index);
		temp_way->pa = 1;
	}
	minimize_way(temp_way);
}

static void	minimize_way(t_way *way)
{
	while (way->ra > 0 && way->rb > 0)
	{
		way->ra--;
		way->rb--;
		way->rr++;
	}
	while (way->rra > 0 && way->rrb > 0)
	{
		way->rra--;
		way->rrb--;
		way->rrr++;
	}
}

static void	fill_way_direct(t_way *temp_way, t_sort *main, int index)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	pos_a = get_position(main->stack_a, index);
	pos_b = get_position(main->stack_b, get_biggest_smaller_index(main->stack_b,
				index));
	if (pos_b == -1)
	{
		pos_b = get_position(main->stack_b, get_biggest_index(main,
					main->stack_b));
	}
	size_a = stack_size(main->stack_a);
	size_b = stack_size(main->stack_b);
	if (pos_a <= size_a / 2)
		temp_way->ra = pos_a;
	else
		temp_way->rra = size_a - pos_a;
	if (pos_b <= size_b / 2)
		temp_way->rb = pos_b;
	else
		temp_way->rrb = size_b - pos_b;
}

static void	fill_way_reverse(t_way *temp_way, t_sort *main, int index)
{
	int	pos_a;
	int	pos_b;
	int	size_a;
	int	size_b;

	pos_a = get_position(main->stack_a, get_smallest_bigger_index(main->stack_a,
				index));
	pos_b = get_position(main->stack_b, index);
	if (pos_a == -1)
	{
		pos_a = get_position(main->stack_a, get_smallest_index(main,
					main->stack_a));
	}
	size_a = stack_size(main->stack_a);
	size_b = stack_size(main->stack_b);
	if (pos_a <= size_a / 2)
		temp_way->ra = pos_a;
	else
		temp_way->rra = size_a - pos_a;
	if (pos_b <= size_b / 2)
		temp_way->rb = pos_b;
	else
		temp_way->rrb = size_b - pos_b;
}

int	get_operations_amount(t_way *way)
{
	int	amount;

	amount = 0;
	if (!way)
		return (amount);
	amount += (way->sa) + (way->sb) + (way->ss);
	amount += (way->ra) + (way->rb) + (way->rr);
	amount += (way->rra) + (way->rrb) + (way->rrr);
	amount += (way->pb) + (way->pa);
	return (amount);
}
