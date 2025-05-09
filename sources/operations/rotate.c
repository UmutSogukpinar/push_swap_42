/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:53 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:36:58 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "actions.h"

void	rotate_a(t_sort *main)
{
	rotate(&(main->stack_a));
	ft_putendl_fd(RA, 1);
}

void	rotate_b(t_sort *main)
{
	rotate(&(main->stack_b));
	ft_putendl_fd(RB, 1);
}

void	rotate_both(t_sort *main)
{
	rotate(&(main->stack_a));
	rotate(&(main->stack_b));
	ft_putendl_fd(RR, 1);
}
