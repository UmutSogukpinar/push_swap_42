/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:23:56 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 02:07:00 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_correct_index(int number, t_list *stack)
{
	int	i;
	int	node_value;

	i = 0;
	while (stack)
	{
		node_value = *(int *)stack->content;
		if (number > node_value)
			return (i);
		i++;
		stack = stack -> next;
	}
	return (i);
}

int	is_in_lower_part(int number, t_list *stack)
{
	int	true_index;
	int	list_size;

	true_index = find_correct_index(number, stack);
	list_size = ft_lstsize(stack);
	if (true_index <= (list_size / 2))
		return (1);
	else
		return (0);
}
