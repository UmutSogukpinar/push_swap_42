/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:13:28 by umut              #+#    #+#             */
/*   Updated: 2024/12/17 21:14:06 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

void	sort_for_two(t_list **stack_a)
{
	t_list	*head;
	t_list	*tail;
	int		head_value;
	int		tail_value;

	head = *stack_a;
	tail = head -> next;
	head_value = *(int *)head -> content;
	tail_value = *(int *)tail -> content;
	if (head_value <= tail_value)
		return ;
	swap_a(stack_a);
}
