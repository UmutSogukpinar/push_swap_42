/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:43:25 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:43:26 by usogukpi         ###   ########.fr       */
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
