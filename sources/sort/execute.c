#include "stdlib.h"
#include "operations.h"

static void execute_opt(void (*op)(t_sort *), t_sort *main, int times);

/*
 * Executes the sequence of operations stored in the 't_way' structure.
 * Uses a generic 'execute_opt' helper to perform each operation multiple times.
 * After execution, frees the 'way' structure and clears its reference.
 */
void execute_way(t_sort *main)
{
	t_way *way;

    way = main->way;
	if (!way)
		return ;
	execute_opt(rotate_b, main, way->rb);
	execute_opt(reverse_rotate_a, main, way->rra);
	execute_opt(reverse_rotate_b, main, way->rrb);
	execute_opt(rotate_a, main, way->ra);
	execute_opt(rotate_both, main, way->rr);
	execute_opt(reverse_rotate_both, main, way->rrr);
	execute_opt(push_a, main, way->pa);
	execute_opt(push_b, main, way->pb);
	free(way);
	main->way = NULL;
}

/*
 * Calls the given operation function 'times' times on the provided sort context.
 */
static void execute_opt(void (*opt)(t_sort *), t_sort *main, int times)
{
	int i = -1;
	while (++i < times)
		opt(main);
}
