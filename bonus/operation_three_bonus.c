/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_three_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:46:58 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/21 12:10:03 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	reverse_rotate_a_bonus(t_bonus *bonus)
{
	reverse_rotate_bonus(&(bonus->stack_a));
}

void	reverse_rotate_b_bonus(t_bonus *bonus)
{
	reverse_rotate_bonus(&(bonus->stack_b));
}

void	reverse_rotate_both_bonus(t_bonus *bonus)
{
	reverse_rotate_bonus(&(bonus->stack_a));
	reverse_rotate_bonus(&(bonus->stack_b));
}
