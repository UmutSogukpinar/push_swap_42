/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:53:18 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 17:53:19 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit((int) str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	find_smallest_bigger_index(t_stack *stack, int index)
{
	int	temp_index;

	temp_index = 2147483647;
	if (!stack)
		return (-1);
	while (stack)
	{
		if ((stack -> index) > index)
			if ((stack -> index) < temp_index)
				temp_index = (stack -> index);
		stack = stack -> next;
	}
	if (temp_index == 2147483647)
		return (-1);
	else
		return (temp_index);
}

int	find_biggest_smaller_index(t_stack *stack, int index)
{
	int	temp_index;

	temp_index = -2147483648;
	if (!stack)
		return (-1);
	while (stack)
	{
		if ((stack -> index) < index)
			if ((stack -> index) > temp_index)
				temp_index = (stack -> index);
		stack = stack -> next;
	}
	if (temp_index == -2147483648)
		return (-1);
	else
		return (temp_index);
}

int	find_pos(t_stack *stack, int index)
{
	int	pos;

	if (!stack)
		return (-1);
	pos = 0;
	while (stack)
	{
		if (index == stack -> index)
			return (pos);
		pos++;
		stack = stack -> next;
	}
	return (-1);
}

int	*create_int_ptr(char *str)
{
	int		*number;

	if (!is_number(str))
		return (NULL);
	if (!is_in_bound(atoi_long(str)))
		return (NULL);
	number = malloc(sizeof(int));
	if (!number)
		return (NULL);
	*number = ft_atoi(str);
	return (number);
}
