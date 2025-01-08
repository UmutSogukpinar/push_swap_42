/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:30:13 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 18:24:50 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	resend(t_sort *main)
{
	while (main -> stack_b)
	{
		create_resend_way(main);
		execute(main);
		free_way(main -> way);
		main -> way = NULL;
	}
	final_touch_resend(main);
}

void	create_resend_way(t_sort *main)
{
	t_stack	*temp_b;
	t_way	*temp_way;

	temp_b = main -> stack_b;
	while (temp_b)
	{
		temp_way = create_alternate_resend_way(main, temp_b -> index);
		update_way(main, temp_way);
		temp_b = temp_b -> next;
	}
}

t_way	*create_alternate_resend_way(t_sort *main, int index)
{
	t_way	*temp_way;

	temp_way = init_way();
	if (!temp_way)
		shut_program_error(main);
	alternate_resend(main , temp_way, index);
	return (temp_way);
}

void	final_touch_resend(t_sort *main)
{
	int	pos_of_smallest;
	int	i;

	pos_of_smallest = find_smallest_pos(main -> stack_a);
	if (pos_of_smallest != 0)
	{
		main -> way = init_way();
		i = -1;
		if (is_in_upper_part(main -> stack_a, pos_of_smallest))
			while (++i < pos_of_smallest)
				list_update(main, &(main -> way -> list), ft_strdup("ra"));
		else
			while (++i < stack_size(main -> stack_a) - pos_of_smallest)
				list_update(main, &(main -> way -> list), ft_strdup("rra"));
		execute(main);
		free_way(main -> way);
		main -> way = NULL;
	}
}
