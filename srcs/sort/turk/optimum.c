/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:17:27 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 17:19:06 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	optimum_way_utils_one(t_sort *main, t_way *alternate, int index)
{
	int	i;
	int	pos;

	if (is_biggest(main -> stack_b, index)
		|| is_smallest(main -> stack_b, index))
	{
		pos = find_biggest_pos(main -> stack_b);
		i = -1;
		if (is_in_upper_part(main -> stack_b, pos))
			while (++i < pos)
				list_update(main, &(alternate -> list), ft_strdup("rb"));
		else
		{
			while (++i < stack_size(main -> stack_b) - pos)
				list_update(main, &(alternate -> list), ft_strdup("rrb"));
		}			
	}
}

void	optimum_way_utils_two(t_sort *main, t_way *alternate, int index)
{
	int	temp_index;
	int	pos;
	int	i;

	if (!(is_biggest(main -> stack_b, index)
			|| is_smallest(main -> stack_b, index)))
	{
		temp_index = find_biggest_smaller_index(main -> stack_b, index);
		if (temp_index == -1)
		{
			free_way(alternate);
			shut_program_error(main);
		}
		pos = find_pos(main -> stack_b, temp_index);
		i = -1;
		if (is_in_upper_part(main -> stack_b, pos))
			while (++i < pos)
				list_update(main, &(alternate -> list), ft_strdup("rb"));
		else
			while (++i < stack_size(main -> stack_b) - pos)
				list_update(main, &(alternate -> list), ft_strdup("rrb"));
	}
}

void	optimum_way_utils_zero(t_sort *main, t_way *alternate, int index)
{
	int	pos;
	int	i;

	pos = find_pos(main -> stack_a, index);
	i = -1;
	if (pos == 0)
	{
		list_update(main, &(alternate -> list), ft_strdup("pb"));
		return ;
	}
	if (is_in_upper_part(main -> stack_a, pos))
	{
		while (++i < pos)
			list_update(main, &(alternate -> list), ft_strdup("ra"));
	}
	else
		while (++i < stack_size(main -> stack_a) - pos)
			list_update(main, &(alternate -> list), ft_strdup("rra"));
	list_update(main, &(alternate -> list), ft_strdup("pb"));
}
