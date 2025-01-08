/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:30:05 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:33:16 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sort.h"
#include "actions.h"

void	push_a(t_sort *main)
{
	push(&(main -> stack_b), &(main -> stack_a));
	ft_printf("pa\n");
}

void	push_b(t_sort *main)
{
	push(&(main -> stack_a), &(main -> stack_b));
	ft_printf("pb\n");
}
