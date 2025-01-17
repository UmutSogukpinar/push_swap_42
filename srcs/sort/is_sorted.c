/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:32 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:44:33 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
