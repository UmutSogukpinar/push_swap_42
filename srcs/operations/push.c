/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:42:41 by umut              #+#    #+#             */
/*   Updated: 2024/12/10 20:10:28 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_printf.h"

void	push_a(t_list **source, t_list **target)
{
	push(source, target);
	ft_printf("pa\n");
}

void	push_b(t_list **source, t_list **target)
{
	push(source, target);
	ft_printf("pb\n");
}
