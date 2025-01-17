/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:34:56 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 17:35:45 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_stack	*create_node(void *content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	node -> index = -1;
	return (node);
}

void	stack_add_back(t_stack **stack, t_stack *new_stack)
{
	t_stack	*temp;

	if (!stack | !new_stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new_stack;
		return ;
	}
	temp = *stack;
	while (temp -> next)
	{
		temp = temp -> next;
	}
	temp -> next = new_stack;
}

void	stack_add_front(t_stack **stack, t_stack *new_stack)
{
	if (!stack || !new_stack)
		return ;
	new_stack -> next = *stack;
	*stack = new_stack;
}

void	stack_update(t_sort *main, void *value)
{
	t_stack	*new;

	new = create_node(value);
	if (!value)
		shut_program_error(main);
	stack_add_back(&(main -> stack_a), new);
}
