/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:38:48 by umut              #+#    #+#             */
/*   Updated: 2025/01/04 21:23:45 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(t_list **stack_a, t_list **stack_b);

void	shut_program(t_list **stack_a, t_list **stack_b)
{
	free_all(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

static void	free_all(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
}
