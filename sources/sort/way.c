#include "stdlib.h"
#include "libft.h"
#include "push_swap.h"
#include "operations.h"

static void update_way(t_sort *main, t_way *temp_way);
static void create_alternative_way(t_sort *main, int index, int mode);

/*
 * Iterates over each element in the active stack (A or B based on mode),
 * and generates a possible t_way (move set) to push that element.
 * Delegates the calculation to create_alternative_way().
 */
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

/*
 * Allocates and fills a t_way struct for moving the element with the given index.
 * Calculates the necessary operations and evaluates if it’s better than the current path.
 * On allocation failure, exits the program with an error.
 */
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

/*
 * Compares the newly created temp_way with the current best path (main->way).
 * Replaces main->way only if the new one requires fewer total operations.
 * Frees the unused t_way to prevent memory leaks.
 */
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
