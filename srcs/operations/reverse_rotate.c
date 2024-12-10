/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:00:26 by umut              #+#    #+#             */
/*   Updated: 2024/12/10 20:05:44 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_printf.h"

void	reverse_rotate_a(t_list **list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_list **list_one, t_list **list_two)
{
	reverse_rotate(list_one);
	reverse_rotate(list_two);
	ft_printf("rrr\n");
}
