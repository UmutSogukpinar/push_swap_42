/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:13:28 by umut              #+#    #+#             */
/*   Updated: 2024/12/18 21:15:44 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sort.h"

void	sort_for_two(t_list **stack)
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

void	sort_for_three(t_list **stack)
{
	int		first_value;
	int		second_value;
	int		third_value;
	t_list	*temp;

	temp = *stack;
	first_value = *(int *)temp->content;
	second_value = *(int *)temp->next->content;
	third_value = *(int *)temp->next->next->content;
	if (first_value > second_value && second_value > third_value)
		sort_three_option_one(stack);
	else if ((first_value < third_value) && (second_value > third_value))
		sort_three_option_two(stack);
	else if ((first_value > second_value) && (third_value > first_value))
		sort_three_option_three(stack);
	else if ((first_value < second_value) && (first_value > third_value))
		sort_three_option_four(stack);
	else if ((first_value > third_value) && (third_value > second_value))
		sort_three_option_five(stack);
}

void	sort_for_three_reverse(t_list **stack)
{
	int		first_value;
	int		second_value;
	int		third_value;
	t_list	*temp;

	if (is_sorted_reverse(*stack))
		return ;
	temp = *stack;
	first_value = *(int *)temp->content;
	second_value = *(int *)temp->next->content;
	third_value = *(int *)temp->next->next->content;
	if (first_value < second_value && second_value < third_value)
		sort_three_reverse_option_one(stack);
	else if ((first_value < third_value) && (second_value > third_value))
		sort_three_reverse_option_two(stack);
	else if ((first_value > second_value) && (third_value > first_value))
		sort_three_reverse_option_three(stack);
	else if ((first_value < second_value) && (first_value > third_value))
		sort_three_reverse_option_four(stack);
	else if ((first_value > third_value) && (third_value > second_value))
		sort_three_reverse_option_five(stack);
}
