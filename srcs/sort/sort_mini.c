/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:52:16 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:52:50 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

void	sort_for_two(t_sort *main)
{
	t_stack	*head;
	t_stack	*tail;
	int		head_value;
	int		tail_value;

	head = (main -> stack_a);
	tail = head -> next;
	head_value = *(int *)head -> content;
	tail_value = *(int *)tail -> content;
	if (head_value <= tail_value)
		return ;
	swap_a(main);
}
