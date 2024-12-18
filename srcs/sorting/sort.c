/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:20:51 by umut              #+#    #+#             */
/*   Updated: 2024/12/18 22:32:01 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	(void) stack_b;
	if (ft_lstsize(*stack_a) == 1)
		return ;
	else if (ft_lstsize(*stack_a) == 2)
		sort_for_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_for_three(stack_a);
	else if (ft_lstsize(*stack_a) >= 4)
		sort_default(stack_a, stack_b);
}
