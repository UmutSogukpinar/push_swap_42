/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:51:09 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 18:43:49 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "utils.h"
#include "ft_printf.h"

void	resend_to_a(t_list **stack_a, t_list **stack_b)
{
	int	b_value;

	(void) b_value;
	while ((*stack_b))
	{
		b_value = *((int *)(*stack_b)->content);
		if (is_biggest(*stack_a, *stack_b))
			resend_the_biggest(stack_a, stack_b);
		else if (is_smallest(*stack_a, *stack_b))
			resend_the_smallest(stack_a, stack_b);
		else
			resend_middles(stack_a, stack_b);
	}
}

void	resend_middles(t_list **stack_a, t_list **stack_b)
{
	resend_for_lower(stack_a, stack_b);
	//int	b_value;

	//b_value = *((int *)(*stack_b)->content);
	//if (!is_in_lower_part(b_value, *stack_a))
	//	resend_for_upper(stack_a, stack_b);
	//if (is_in_lower_part(b_value, *stack_a))
	//	resend_for_lower(stack_a, stack_b);
}

//void	resend_for_upper(t_list **stack_a, t_list **stack_b)
//{
//	int	b_value;
//	int	a_value;
//	int	tail_value;

//	b_value = *((int *)(*stack_b)->content);
//	a_value = *((int *)(*stack_a)->content);
//	while (*stack_b)
//	{
//		resend_for_upper_utils(stack_a, stack_b);
//		if (*stack_b && (tail_value > b_value))
//			resend_for_upper_utils(stack_a, stack_b);
//	}
//}

void	resend_for_lower(t_list **stack_a, t_list **stack_b)
{
	int	b_value;
	int	a_value;
	int	tail_value;

	b_value = *((int *)(*stack_b)->content);
	a_value = *((int *)(*stack_a)->content);
	tail_value = *(int *)(get_tail(*stack_a) -> content);
	while (*stack_b)
	{
		resend_for_lower_utils(stack_a, stack_b);
		while (*stack_b && (a_value > b_value)
			&& (tail_value > b_value) && !is_smallest(*stack_a, *stack_b))
		{
			rotate_a(stack_a);
		}
		while (*stack_b && is_smallest(*stack_a, *stack_b))
		{
			while (!is_sorted(*stack_a))
				reverse_rotate_a(stack_a);
			push_a(stack_b, stack_a);
		}
	}
}