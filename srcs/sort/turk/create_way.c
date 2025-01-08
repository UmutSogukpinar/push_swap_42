/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:23:05 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 18:28:59 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	create_way(t_sort *main)
{
	t_stack	*temp_a;
	t_way	*temp_way;

	temp_a = main -> stack_a;
	while (temp_a)
	{
		temp_way = create_alternate_way(main, temp_a -> index);
		update_way(main, temp_way);
		temp_a = temp_a -> next;
	}
}

t_way	*create_alternate_way(t_sort *main, int index)
{
	t_way	*temp_way;

	temp_way = init_way();
	if (!temp_way)
		shut_program_error(main);
	alternate_way(main, temp_way, index);
	return (temp_way);
}

void	alternate_way(t_sort *main, t_way *temp_way, int index)
{
	optimum_way_utils_zero(main, temp_way, index);	
	optimum_way_utils_one(main, temp_way, index);
	optimum_way_utils_two(main, temp_way, index);
}

void	final_touch(t_sort *main)
{
	int	pos_of_biggest;
	int	i;

	pos_of_biggest = find_biggest_pos(main -> stack_b);
	if (pos_of_biggest != 0)
	{
		main -> way = init_way();
		i = -1;
		if (is_in_upper_part(main -> stack_b, pos_of_biggest))
			while (++i < pos_of_biggest)
				list_update(main, &(main -> way -> list), ft_strdup("rb"));
		else
			while (++i < stack_size(main -> stack_b) - pos_of_biggest)
				list_update(main, &(main -> way -> list), ft_strdup("rrb"));
		execute(main);
		free_way(main -> way);
		main -> way = NULL;
	}
}
