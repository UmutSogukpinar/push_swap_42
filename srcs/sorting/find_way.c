/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:01:44 by umut              #+#    #+#             */
/*   Updated: 2025/01/06 20:28:05 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "utils.h"
#include "ft_printf.h"

int	reverse_sort(t_sort *s_strct)
{
	t_list	*temp_a;
	int		is_problem;
	int		a_value;

	is_problem = 0;
	temp_a = s_strct -> stack_a;
	while (temp_a)
	{
		a_value = *(int *)(temp_a -> content);
		is_problem = find_way(s_strct, a_value);
		if (is_problem != 0)
			shut_program(&(s_strct -> stack_a), &(s_strct -> stack_b));
		temp_a = temp_a -> next;
	}
	execute_way(s_strct -> way -> move_list, s_strct);
	return (0);
}

int	find_way(t_sort *s_strct, int value)
{
	int		index;
	int		is_problem;
	t_way	*temp_way;

	temp_way = malloc(sizeof(t_way));
	if (!temp_way)
		return (-1);
	init_temp_way(temp_way);
	get_upper_head(temp_way, (s_strct -> stack_a), value);
	index = find_correct_index(value, s_strct -> stack_b);
	if (index < 0)
		return (-1);
	is_problem = 0;
	ft_printf("helper works for: %d\n", value);
	is_problem += find_way_helper_one(s_strct, index, temp_way);
	is_problem += find_way_helper_two(s_strct, index, temp_way);
	if (is_problem < 0)
	{
		free_way(temp_way);
		return (-1);
	}
	update_way(s_strct, temp_way);
	return (0);
}

void	update_way(t_sort *s_strct, t_way *temp)
{
	ft_printf("created stack:\n");
	ft_display_str_list(temp -> move_list);
	if ((s_strct -> way -> move_num) > (temp -> move_num)
		&& (temp -> move_num) > 0)
	{
		ft_lstclear(&(s_strct -> way -> move_list), free);
		s_strct -> way -> move_list = temp -> move_list;
		s_strct -> way -> move_num = temp -> move_num;
	}
	else if ((s_strct -> way -> move_num) <= (temp -> move_num)
		&& (temp -> move_num) > 0)
	{
		free_way(temp);
	}
}
