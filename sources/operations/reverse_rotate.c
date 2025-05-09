/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:35 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:36:52 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "actions.h"

void	reverse_rotate_a(t_sort *main)
{
	reverse_rotate(&(main->stack_a));
	ft_putendl_fd(RRA, 1);
}

void	reverse_rotate_b(t_sort *main)
{
	reverse_rotate(&(main->stack_b));
	ft_putendl_fd(RRB, 1);
}

void	reverse_rotate_both(t_sort *main)
{
	reverse_rotate(&(main->stack_a));
	reverse_rotate(&(main->stack_b));
	ft_putendl_fd(RRR, 1);
}
