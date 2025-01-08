/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:33:28 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 19:59:30 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sort.h"
#include "actions.h"

void	swap_a(t_sort *main)
{
	swap(&(main -> stack_a));
	ft_printf("sa\n");
}

void	swap_b(t_sort *main)
{
	swap(&(main -> stack_b));
	ft_printf("sb\n");
}

void	swap_both(t_sort *main)
{
	swap(&(main -> stack_a));
	swap(&(main -> stack_b));
	ft_printf("ss\n");
}
