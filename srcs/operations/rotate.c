/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:56:34 by umut              #+#    #+#             */
/*   Updated: 2024/12/10 20:00:05 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_printf.h"

void	rotate_a(t_list **list)
{
	rotate(list);
	ft_printf("ra\n");
}

void	rotate_b(t_list **list)
{
	rotate(list);
	ft_printf("rb\n");
}

void	rotate_both(t_list **list_one, t_list **list_two)
{
	rotate(list_one);
	rotate(list_two);
	ft_printf("rr\n");
}
