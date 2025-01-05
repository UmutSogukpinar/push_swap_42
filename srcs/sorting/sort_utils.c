/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:21:07 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 01:34:50 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sort.h"

void	stack_b_setup(t_list **src, t_list **target)
{
	push_b(src, target);
	push_b(src, target);
	push_b(src, target);
	sort_for_three_reverse(target);
}

void	stack_a_setup(t_list **stack_a)
{
	if (!(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 1)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
		sort_for_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_for_three(stack_a);
}
