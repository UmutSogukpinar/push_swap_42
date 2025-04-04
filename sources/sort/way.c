#include "push_swap.h"
#include "operations.h"

static void update_way(t_sort *main, t_way *temp_way);
static void create_alternative_way(t_sort *main, int index, int mode);

void create_way(t_sort *main, int mode)
{
	t_stack	*temp;

	if (mode == A_TO_B)
		temp = main->stack_a;
	else if (mode == B_TO_A)
		temp = main->stack_b;
	while (temp)
	{
		create_alternative_way(main, temp->index, mode);
		temp = temp->next;
	}
}

static void create_alternative_way(t_sort *main, int index, int mode)
{
	t_way *temp_way;

	temp_way = ft_calloc(1, sizeof(t_way));
	if (!temp_way)
		shut_program_error(main,
					"Error: Memory allocation failed on create_alternate_way()");
	fill_way(temp_way, main, index, mode);
	update_way(main, temp_way);
}

static void update_way(t_sort *main, t_way *temp_way)
{
	if (!main->way)
	{
		main->way = temp_way;
		return ;
	}
	if (get_operations_amount(main->way) > get_operations_amount(temp_way))
	{
		free(main->way);
		main->way = temp_way;
	}
	else
		free(temp_way);
}
