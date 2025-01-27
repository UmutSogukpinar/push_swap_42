/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:33:42 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/23 15:09:29 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	is_list_sorted(t_list *list)
{
	int	value;
	int	compared_value;

	if (!list || !list->content)
		return (0);
	while (list->next)
	{
		value = *(int *)(list->content);
		if (!list->next->content)
			return (0);
		compared_value = *(int *)(list->next->content);
		if (value > compared_value)
			return (0);
		list = list->next;
	}
	return (1);
}

int	last_checks(t_bonus *bonus)
{
	if (bonus->stack_b || !(bonus->stack_a))
		return (0);
	if (is_list_sorted(bonus->stack_a))
		return (1);
	else
		return (0);
}

void	check_duplicate_bonus(t_bonus *bonus)
{
	t_list	*list_one;
	t_list	*list_two;

	if (!bonus || !(bonus->stack_a))
		return ;
	list_one = bonus->stack_a;
	while (list_one)
	{
		list_two = list_one->next;
		while (list_two)
		{
			if (list_one->content && list_two->content
				&& is_numbers_equal_bonus((int *)list_one->content,
					(int *)list_two->content))
				exit_error(bonus);
			list_two = list_two->next;
		}
		list_one = list_one->next;
	}
}
