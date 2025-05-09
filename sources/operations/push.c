/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:16:16 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:36:47 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "actions.h"

void	push_a(t_sort *main)
{
	push(&(main->stack_b), &(main->stack_a));
	ft_putendl_fd(PA, 1);
}

void	push_b(t_sort *main)
{
	push(&(main->stack_a), &(main->stack_b));
	ft_putendl_fd(PB, 1);
}
