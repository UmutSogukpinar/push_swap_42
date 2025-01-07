/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:33:05 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 13:09:48 by umut             ###   ########.fr       */
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

void	stack_add(t_stack **stack, t_stack *new_stack)
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

void	stack_update(t_sort *main, int *value)
{
	t_stack *new;

	new = create_node(value);
	if (!value)
		shut_program_error(main);
	stack_add(&(main -> stack_a), new);
}

void	stack_clear(t_stack **stack, void (*del)(void *))
{
	t_stack	*temp;
	if (!stack | !del)
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
