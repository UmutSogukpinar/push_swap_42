/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:43:52 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:43:53 by usogukpi         ###   ########.fr       */
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
