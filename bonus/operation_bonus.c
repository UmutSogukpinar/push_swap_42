/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:37:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/21 12:09:30 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	push_a_bonus(t_bonus *bonus)
{
	push_bonus(&(bonus->stack_b), &(bonus->stack_a));
}

void	push_b_bonus(t_bonus *bonus)
{
	push_bonus(&(bonus->stack_a), &(bonus->stack_b));
}

void	swap_a_bonus(t_bonus *bonus)
{
	swap_bonus(&(bonus->stack_a));
}

void	swap_b_bonus(t_bonus *bonus)
{
	swap_bonus(&(bonus->stack_b));
}

void	swap_both_bonus(t_bonus *bonus)
{
	swap_bonus(&(bonus->stack_a));
	swap_bonus(&(bonus->stack_b));
}
