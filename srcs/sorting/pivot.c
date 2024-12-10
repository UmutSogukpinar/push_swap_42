/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:29:34 by umut              #+#    #+#             */
/*   Updated: 2024/12/10 20:21:47 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

int	get_average(t_list *list)
{
	int	acc;
	int	stack_size;

	acc = 0;
	stack_size = ft_lstsize(list);
	if (stack_size == 0)
		return (0);
	while (list)
	{
		acc += (int)(list -> content);
		list = list -> next;
	}
	return (acc / stack_size);
}

int	get_pivot(t_list *list)
{
	int	pivot;
	int	median;
	int	list_value;

	pivot = (int) list->content;
	median = get_average(list);
	while (list)
	{
		list_value = (int) list -> content;
		if (get_abs(list_value - median) < get_abs(pivot - median))
			pivot = list_value;
		list = list -> next;
	}
	return (pivot);
}
