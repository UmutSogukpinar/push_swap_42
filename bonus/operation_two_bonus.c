/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_two_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:44:48 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/21 12:10:06 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rotate_a_bonus(t_bonus *bonus)
{
	rotate_bonus(&(bonus->stack_a));
}

void	rotate_b_bonus(t_bonus *bonus)
{
	rotate_bonus(&(bonus->stack_b));
}

void	rotate_both_bonus(t_bonus *bonus)
{
	rotate_bonus(&(bonus->stack_a));
	rotate_bonus(&(bonus->stack_b));
}
