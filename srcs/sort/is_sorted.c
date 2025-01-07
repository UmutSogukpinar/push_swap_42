/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:34:42 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:47:46 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

int	is_sorted(t_stack *stack)
{
	int	value;

	if (stack_size(stack) <= 1)
		return (1);
	value = *(int *)(stack -> content);
	stack = stack -> next;
	while (stack)
	{
		if ((*(int *)(stack -> content)) < value)
			return (0);
		value = *(int *)(stack -> content);
		stack = stack -> next;
	}
	return (1);
}
