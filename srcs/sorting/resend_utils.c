/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resend_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:59:48 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 21:08:10 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "utils.h"
#include "ft_printf.h"

void	resend_the_biggest(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_b, stack_a);
	rotate_a(stack_a);
}

void	resend_the_smallest(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_b, stack_a);
}

void	resend_for_lower_utils(t_list **stack_a, t_list **stack_b)
{
	int	b_value;
	int	a_value;
	int	tail_value;

	b_value = *((int *)(*stack_b)->content);
	a_value = *((int *)(*stack_a)->content);
	tail_value = *(int *)(get_tail(*stack_a) -> content);
	while (*stack_b && (tail_value > b_value))
	{
		reverse_rotate_a(stack_a);
		a_value = *((int *)(*stack_a)->content);
		tail_value = *(int *)(get_tail(*stack_a) -> content);
	}
	while (*stack_b && (a_value > b_value) && (b_value > tail_value))
	{
		push_a(stack_b, stack_a);
		a_value = *((int *)(*stack_a)->content);
		if (*stack_b)
			b_value = *((int *)(*stack_b)->content);
	}
}

void	resend_for_upper_utils(t_list **stack_a, t_list **stack_b)
{
	int	b_value;
	int	a_value;
	int	tail_value;

	b_value = *((int *)(*stack_b)->content);
	a_value = *((int *)(*stack_a)->content);
	while (*stack_b)
	{
		while (*stack_b && (b_value > a_value))
		{
			rotate_a(stack_a);
			a_value = *((int *)(*stack_a)->content);
		}
		tail_value = *(int *)(get_tail(*stack_a) -> content);
		while (*stack_b && (b_value < a_value) && (b_value > tail_value))
		{
			push_a(stack_b, stack_a);
			b_value = *((int *)(*stack_b)->content);
			a_value = *((int *)(*stack_a)->content);
		}
	}
	while (tail_value > b_value)
	{
		reverse_rotate_a(stack_a);
		b_value = *((int *)(*stack_b)->content);
		tail_value = *(int *)(get_tail(*stack_a) -> content);
	}
}
