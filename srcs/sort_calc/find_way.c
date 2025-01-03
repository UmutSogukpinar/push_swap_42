/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:01:44 by umut              #+#    #+#             */
/*   Updated: 2025/01/04 00:35:54 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "utils.h"

int		update_way(t_way *opt, t_list **stack_a, t_list **stack_b)
{
	t_list	*move_list;
	t_list	*temp;

	temp = *stack_a;
	while (temp)
	{
		find_way(opt, *stack_b, *(int *)(temp -> content));
		temp = temp -> next;
	}
	return (0);	
}

void	find_way(t_way *opt, t_list *stack_b, int value)
{
	t_list	*temp_b;

	temp_b = stack_b;
	find_correct_index(value, stack_b);

}
