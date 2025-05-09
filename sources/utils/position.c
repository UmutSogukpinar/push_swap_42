/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:45:05 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:31:17 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

int	get_biggest_smaller_index(t_stack *stack, int given_index)
{
	int	max_index;

	max_index = -1;
	while (stack)
	{
		if (stack->index < given_index && stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

int	get_smallest_bigger_index(t_stack *stack, int given_index)
{
	int	min_index;

	min_index = MAX_INT;
	while (stack)
	{
		if (stack->index > given_index && stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	if (min_index == MAX_INT)
		return (-1);
	return (min_index);
}

int	get_biggest_index(t_sort *main, t_stack *stack)
{
	int	max_index;

	if (!stack)
		shut_program_error(main,
			"Error: Stack is empty in get_biggest_index()");
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}

int	get_smallest_index(t_sort *main, t_stack *stack)
{
	int	min_index;

	if (!stack)
		shut_program_error(main,
			"Error: Stack is empty in get_smallest_index()");
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}
