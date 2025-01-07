/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:36:02 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:47:32 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
}

void	stack_clear(t_stack **stack, void (*del)(void *))
{
	t_stack	*temp;

	if (!stack || !del)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)-> next;
		del(temp -> content);
		free(temp);
	}
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
	{
		stack = stack -> next;
	}
	return (stack);
}
