/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:50:53 by umut              #+#    #+#             */
/*   Updated: 2025/01/06 20:37:57 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "utils.h"
#include "ft_printf.h"


int	update_list(t_list **list, char *command)
{
	t_list	*node;
	char	*content;

	content = ft_strdup(command);
	if (!content)
		return (-10000);
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (-10000);
	}
	ft_lstadd_back(list, node);
	return (1);
}

void	get_upper_head(t_way *temp, t_list *stack_a, int value)
{
	int	index;
	int	move_num;
	int	i;

	index = find_actual_index(value, stack_a);
	if (index < 0)
	{
		temp -> move_num = -1000;
		return ;
	}
	i = -1;
	if (index <= (ft_lstsize(stack_a) / 2))
	{
		move_num = index;
		while (++i < move_num)
			temp -> move_num += update_list(&(temp -> move_list), "ra");
	}
	else
	{
		move_num = ft_lstsize(stack_a) - index;
		while (++i < move_num)
			temp -> move_num  += update_list(&(temp -> move_list), "rra");
	}
}

int	find_way_helper_two(t_sort *s_strct, int index, t_way *temp)
{
	int	move_num;
	int	i;

	i = -1;
	if (index > (ft_lstsize(s_strct -> stack_b) / 2))
	{
		move_num = ft_lstsize(s_strct -> stack_b) - index;
		while (++i < move_num)
			temp -> move_num += update_list(&(temp -> move_list), "rrb");
		temp -> move_num += update_list(&(temp -> move_list), "pb");
		i = -1;
		while (++i < move_num + 1)
			temp -> move_num += update_list(&(temp -> move_list), "rb");
		if (temp -> move_num <= 0)
			return (-1);
	}
	return (0);
}

int	find_way_helper_one(t_sort *s_strct, int index, t_way *temp)
{
	int	move_num;
	int	i;

	i = -1;
	if (index <= (ft_lstsize(s_strct -> stack_b) / 2))
	{
		move_num = index;
		while (++i < move_num)
			temp -> move_num += update_list(&(temp -> move_list), "rb");
		temp -> move_num += update_list(&(temp -> move_list), "pb");
		i = -1;
		while (++i < move_num)
			temp -> move_num += update_list(&(temp -> move_list), "rrb");
		if (temp -> move_num <= 0)
			return (-1);
	}
	return (0);
}
