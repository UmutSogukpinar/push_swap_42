/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_reverse_helper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:30:05 by umut              #+#    #+#             */
/*   Updated: 2024/12/18 11:23:42 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sort_three_reverse_option_one(t_list **stack)
{
	swap_b(stack);
	reverse_rotate_b(stack);
}

void	sort_three_reverse_option_two(t_list **stack)
{
	rotate_b(stack);
}

void	sort_three_reverse_option_three(t_list **stack)
{
	reverse_rotate_b(stack);
}

void	sort_three_reverse_option_four(t_list **stack)
{
	swap_b(stack);
}

void	sort_three_reverse_option_five(t_list **stack)
{
	swap_b(stack);
	rotate_b(stack);
}
