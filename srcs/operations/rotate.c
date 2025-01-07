/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:34:31 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:36:48 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sort.h"
#include "actions.h"

void	rotate_a(t_sort *main)
{
	rotate(&(main -> stack_a));
	ft_printf("ra\n");
}

void	rotate_b(t_sort *main)
{
	rotate(&(main -> stack_b));
	ft_printf("rb\n");
}

void	rotate_both(t_sort *main)
{
	rotate(&(main -> stack_a));
	rotate(&(main -> stack_b));
	ft_printf("rr\n");
}
