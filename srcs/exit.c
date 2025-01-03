/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:38:48 by umut              #+#    #+#             */
/*   Updated: 2025/01/03 23:44:21 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	shut_program(t_list **stack_a, t_list **stack_b)
{
	free(stack_a, stack_b);
	exit(EXIT_FAILURE);
}

static void	free(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
}
