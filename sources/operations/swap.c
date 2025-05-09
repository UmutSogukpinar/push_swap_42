/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:17:08 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:37:05 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "actions.h"

void	swap_a(t_sort *main)
{
	swap(&(main->stack_a));
	ft_putendl_fd(SA, 1);
}

void	swap_b(t_sort *main)
{
	swap(&(main->stack_b));
	ft_putendl_fd(SB, 1);
}

void	swap_both(t_sort *main)
{
	swap(&(main->stack_a));
	swap(&(main->stack_b));
	ft_putendl_fd(SS, 1);
}
