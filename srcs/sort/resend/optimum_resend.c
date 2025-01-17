/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimum_resend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:10:55 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 17:15:27 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	opt_rsnd_utils_one(t_sort *main, t_way *alternate, int index)
{
	int	pos;
	int	i;

	if (is_biggest(main -> stack_a, index)
		|| is_smallest(main -> stack_a, index))
	{
		pos = find_smallest_pos(main -> stack_a);
		if (pos == 0)
			list_update(main, &(alternate -> list), ft_strdup("pa"));
		else
		{
			i = -1;
			if (is_in_upper_part(main -> stack_a, pos))
				while (++i < pos)
					list_update(main, &(alternate -> list), ft_strdup("ra"));
			else
				while (++i < stack_size(main -> stack_a) - pos)
					list_update(main, &(alternate -> list), ft_strdup("rra"));
			list_update(main, &(alternate -> list), ft_strdup("pa"));
		}
	}
}

void	opt_rsnd_utils_two(t_sort *main, t_way *alternate, int index)
{
	int	temp_index;
	int	pos;
	int	i;

	if (!(is_biggest(main -> stack_a, index)
			|| is_smallest(main -> stack_a, index)))
	{
		temp_index = find_smallest_bigger_index(main -> stack_a, index);
		if (temp_index == -1)
		{
			free_way(alternate);
			shut_program_error(main);
		}
		pos = find_pos(main -> stack_a, temp_index);
		i = -1;
		if (is_in_upper_part(main -> stack_a, pos))
			while (++i < pos)
				list_update(main, &(alternate -> list), ft_strdup("ra"));
		else
			while (++i < stack_size(main -> stack_a) - pos)
				list_update(main, &(alternate -> list), ft_strdup("rra"));
		list_update(main, &(alternate -> list), ft_strdup("pa"));
	}
}

void	opt_rsnd_utils_zero(t_sort *main, t_way *alternate, int index)
{
	int	pos;
	int	i;

	pos = find_pos(main -> stack_b, index);
	i = -1;
	if (pos == 0)
		return ;
	else if (is_in_upper_part(main -> stack_b, pos))
	{
		while (++i < pos)
			list_update(main, &(alternate -> list), ft_strdup("rb"));
	}
	else
		while (++i < stack_size(main -> stack_b) - pos)
			list_update(main, &(alternate -> list), ft_strdup("rrb"));
}
