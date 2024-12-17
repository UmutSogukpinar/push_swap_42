/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:13:28 by umut              #+#    #+#             */
/*   Updated: 2024/12/17 23:58:00 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sort.h"

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

void	sort_for_three(t_list **stack_a, t_list **stack_b)
{
	int		first_value;
	int		second_value;
	int		third_value;
	t_list	*temp;

	(void)	**stack_b;
	temp = *stack_a;
	first_value = *(int *)temp->content;
	second_value = *(int *)temp->next->content;
	third_value = *(int *)temp->next->next->content;
	if (first_value > second_value && second_value > third_value)
		sort_three_option_one(stack_a);
	else if ((first_value > second_value) && (second_value < third_value))
		sort_three_option_sec(stack_a);
	else if ((first_value < second_value) && (second_value > third_value))
		sort_three_option_third(stack_a);
	else if ((first_value > second_value) && (second_value < third_value))
		sort_three_option_fourth(stack_a);
	else if ((first_value < second_value) && (second_value > third_value))
		sort_three_option_fifth(stack_a);
}
