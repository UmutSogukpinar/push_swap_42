/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:56:53 by umut              #+#    #+#             */
/*   Updated: 2024/12/10 22:14:07 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sorted(t_list *list)
{
	int	value;

	if (ft_lstsize(list) <= 1)
		return (1);
	value = *(int *)(list -> content);
	list = list -> next;
	while (list)
	{
		if ((*(int *)(list -> content)) < value)
			return (0);
		value = *(int *)(list -> content);
		list = list -> next;
	}
	return (1);
}

int	is_sorted_reverse(t_list *list)
{
	int	value;

	if (ft_lstsize(list) <= 1)
		return (1);
	value = *(int *)(list -> content);
	list = list -> next;
	while (list)
	{
		if ((*(int *)(list -> content)) > value)
			return (0);
		value = *(int *)(list -> content);
		list = list -> next;
	}
	return (1);
}
