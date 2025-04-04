#include "operations.h"
#include "stdlib.h"

static void execute_way2(t_sort *main);
static void execute_way3(t_sort *main);

void execute_way(t_sort *main)
{
	int		i;
	t_way	*way;

	way = main->way;
	if (!way)
		return ;
	i = -1;
	while (++i < way->rb)
	{
		rotate_b(main);
	}
	i = -1;
	while (++i < way->rra)
	{
		reverse_rotate_a(main);
	}
	i = -1;
	while (++i < way->rrb)
	{
		reverse_rotate_b(main);
	}
	execute_way2(main);
}

static void execute_way2(t_sort *main)
{
	int		i;
	t_way	*way;

	i = -1;
	way = main->way;
	while (++i < way->ra)
	{
		rotate_a(main);
	}
	i = -1;
	while (++i < way->rr)
	{
		rotate_both(main);
	}
	i = -1;
	while (++i < way->rrr)
	{
		reverse_rotate_both(main);
	}
	execute_way3(main);
}

static void execute_way3(t_sort *main)
{
	int		i;
	t_way	*way;

	way = main->way;
	i = -1;
	while (++i < way->pa)
	{
		push_a(main);
	}
	i = -1;
	while (++i < way->pb)
	{
		push_b(main);
	}
	free(way);
	main->way = NULL;
}
