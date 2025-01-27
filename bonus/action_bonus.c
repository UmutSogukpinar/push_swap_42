/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:03:13 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/20 17:53:40 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_bonus(t_list **source, t_list **target)
{
	t_list	*source_head;
	t_list	*new_head;

	if (!(source && *source))
		return ;
	source_head = *source;
	new_head = (*source)->next;
	*source = new_head;
	source_head->next = NULL;
	ft_lstadd_front(target, source_head);
}

void	swap_bonus(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}

void	rotate_bonus(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;
	t_list	*last_node;

	if (ft_lstsize(*stack) <= 1)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	*stack = second_node;
	last_node->next = first_node;
	first_node->next = NULL;
}

void	reverse_rotate_bonus(t_list **stack)
{
	t_list	*last_node;
	t_list	*scnd_to_last_node;

	if (ft_lstsize(*stack) <= 1)
		return ;
	if (ft_lstsize(*stack) == 2)
	{
		rotate_bonus(stack);
		return ;
	}
	scnd_to_last_node = *stack;
	while (scnd_to_last_node->next->next)
		scnd_to_last_node = scnd_to_last_node->next;
	last_node = scnd_to_last_node->next;
	last_node->next = *stack;
	scnd_to_last_node->next = NULL;
	*stack = last_node;
}
