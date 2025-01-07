/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:52:16 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 13:53:40 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

// I stay there!!!!

void	sort_for_two(t_sort *main)
{
	t_list	*head;
	t_list	*tail;
	int		head_value;
	int		tail_value;

	head = *stack;
	tail = head -> next;
	head_value = *(int *)head -> content;
	tail_value = *(int *)tail -> content;
	if (head_value <= tail_value)
		return ;
	swap_a(stack);
}