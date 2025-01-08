/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate_resend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:10:25 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 14:42:46 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	alternate_resend(t_sort *main, t_way *alternate, int index)
{
	opt_rsnd_utis_one(main, alternate, index);
	opt_rsnd_utis_two(main, alternate, index);
	alternate -> amount = ft_lstsize(alternate -> list);
}

void	opt_rsnd_utis_one(t_sort *main, t_way *alternate, int index)
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

void	opt_rsnd_utis_two(t_sort *main, t_way *alternate, int index)
{
	int	temp_index;
	int	pos;
	int	i;

	if (!(is_biggest(main -> stack_a, index)
		|| is_smallest(main -> stack_a, index)))
	{
		temp_index = find_smallest_bigger_index(main -> stack_a, index);
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
