/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:53:03 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 00:30:04 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

int	is_in_upper_part(t_stack *stack, int pos)
{
	int stack_len;

	stack_len = stack_size(stack);
	if (pos <= (stack_len / 2) && stack_len % 2 == 1)
		return (1);
	else if (pos < stack_len / 2)
		return (1);
	else
		return (0);
}

int	is_biggest(t_stack *stack, int index)
{
	int	temp_index;

	(void) temp_index;
	while (stack)
	{
		temp_index = (stack -> index);
		if (temp_index > index)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

int	find_biggest_pos(t_stack *stack)
{
	int	index;
	int	temp_index;
	int	position;
	int	position_biggest;

	position = 0;
	position_biggest = 0;
	if (!stack)
		return (-1);
	index = stack -> index;
	while (stack)
	{
		temp_index = stack -> index;
		if (temp_index > index)
		{
			index = temp_index;
			position_biggest = position;
		}
		position++;
		stack = stack -> next;
	}
	return (position_biggest);
}

int	is_smallest(t_stack *stack, int index)
{
	int	temp_index;

	(void) temp_index;
	while (stack)
	{
		temp_index = (stack -> index);
		if (temp_index < index)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

int	find_smallest_pos(t_stack *stack)
{
	int	index;
	int	temp_index;
	int	position;
	int	position_smallest;

	position = 0;
	position_smallest = 0;
	if (!stack)
		return (-1);
	index = stack -> index;
	while (stack)
	{
		temp_index = stack -> index;
		if (temp_index < index)
		{
			index = temp_index;
			position_smallest = position;
		}
		position++;
		stack = stack -> next;
	}
	return (position_smallest);
}
