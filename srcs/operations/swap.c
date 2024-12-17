/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:54:30 by umut              #+#    #+#             */
/*   Updated: 2024/12/18 00:04:31 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_printf.h"

void	swap_a(t_list **list)
{
	swap(list);
	ft_printf("sa\n");
}

void	swap_b(t_list **list)
{
	swap(list);
	ft_printf("sb\n");
}

void	swap_both(t_list **list_one, t_list **list_two)
{
	swap(list_one);
	swap(list_two);
	ft_printf("ss\n");
}
