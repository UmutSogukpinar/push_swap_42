/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:23:56 by umut              #+#    #+#             */
/*   Updated: 2024/12/18 21:32:17 by umut             ###   ########.fr       */
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
