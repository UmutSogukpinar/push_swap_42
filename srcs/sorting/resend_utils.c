/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resend_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:59:48 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 11:34:11 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "utils.h"

void	resend_the_biggest(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_b, stack_a);
	rotate_a(stack_a);
}

void	resend_the_smallest(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_b, stack_a);
}

void	resend_for_upper_utils(t_list **stack_a, t_list **stack_b)
{
	int	b_value;
	int	tail_value;

	b_value = *((int *)(*stack_b)->content);
	tail_value = *(int *)(get_tail(*stack_a) -> content);
	while (tail_value > b_value)
	{
		reverse_rotate_a(stack_a);
		b_value = *((int *)(*stack_b)->content);
		tail_value = *(int *)(get_tail(*stack_a) -> content);
	}
}
