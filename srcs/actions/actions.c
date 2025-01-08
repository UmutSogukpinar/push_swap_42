/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:20:39 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:51:27 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sort.h"
#include "stack.h"

void	push(t_stack **source, t_stack **target)
{
	t_stack	*source_head;
	t_stack	*new_head;

	if (!(source && *source))
		return ;
	source_head = *source;
	new_head = (*source)->next;
	*source = new_head;
	source_head->next = NULL;
	stack_add_front(target, source_head);
}

void	swap(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = first_node -> next;
	first_node -> next = second_node -> next;
	second_node -> next = first_node;
	*stack = second_node;
}

void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	if (stack_size(*stack) <= 1)
		return ;
	first_node = *stack;
	second_node = first_node -> next;
	last_node = *stack;
	while (last_node -> next)
		last_node = last_node -> next;
	*stack = second_node;
	last_node -> next = first_node;
	first_node -> next = NULL;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*scnd_to_last_node;

	if (stack_size(*stack) <= 1)
		return ;
	if (stack_size(*stack) == 2)
	{
		rotate(stack);
		return ;
	}
	scnd_to_last_node = *stack;
	while (scnd_to_last_node -> next -> next)
		scnd_to_last_node = scnd_to_last_node -> next;
	last_node = scnd_to_last_node -> next;
	last_node -> next = *stack;
	scnd_to_last_node -> next = NULL;
	*stack = last_node;
}
