/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:44:24 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 13:15:27 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sort.h"

void	display_int_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->content)
			ft_printf("Node %d: %d\n", i, *(int *)(stack->content));
		else
			ft_printf("Node %d: (null)\n", i);
		stack = stack->next;
		i++;
	}
}

void	ft_display_str_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->content)
			ft_printf("Node %d: %s\n", i, (char *)(stack->content));
		else
			ft_printf("Node %d: (null)\n", i);
		stack = stack->next;
		i++;
	}
}
