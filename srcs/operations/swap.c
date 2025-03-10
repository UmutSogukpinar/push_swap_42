/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:43:52 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/21 12:41:38 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_printf.h"
#include "sort.h"

void	swap_a(t_sort *main)
{
	swap(&(main->stack_a));
	ft_printf("sa\n");
}

void	swap_b(t_sort *main)
{
	swap(&(main->stack_b));
	ft_printf("sb\n");
}
