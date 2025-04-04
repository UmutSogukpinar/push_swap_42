#include "structures.h"
#include "push_swap.h"

void    create_way(t_sort *main)
{
	t_stack	*temp_a;
	t_way	*temp_way;

	temp_a = main -> stack_a;
	while (temp_a)
	{
		// TODO: temp_way = create_alternate_way(main, temp_a -> index);
		// TODO: update_way(main, temp_way);
		temp_a = temp_a -> next;
	}
}

static t_way *create_alternative_way(t_sort *main, int index)
{
    t_way	*temp_way;

    temp_way = ft_calloc(1, sizeof(t_way));
    if (!temp_way)
        shut_program_error(main, 
            "Error: Memory allocation failed on create_alternate_way()");
    fill_way(temp_way, main, index, A_TO_B);

}

static void fill_way(t_way *temp_way, t_sort *main, int index, int mode)
{
    if (mode == A_TO_B)
        fill_way_one(temp_way, main, index);
}

static void fill_way_one(t_way *temp_way, t_sort *main, int index)
{

}
