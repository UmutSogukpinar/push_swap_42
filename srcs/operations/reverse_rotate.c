/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:43:33 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:43:34 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sort.h"
#include "actions.h"

void	reverse_rotate_a(t_sort *main)
{
	reverse_rotate(&(main -> stack_a));
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_sort *main)
{
	reverse_rotate(&(main -> stack_b));
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_sort *main)
{
	reverse_rotate(&(main -> stack_a));
	reverse_rotate(&(main -> stack_b));
	ft_printf("rrr\n");
}
