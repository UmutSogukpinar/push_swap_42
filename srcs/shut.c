/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:20 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:46:19 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "sort.h"
#include "stack.h"

static void	free_all(t_sort *main);

void	shut_program_error(t_sort *main)
{
	free_all(main);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	shut_program_default(t_sort *main)
{
	free_all(main);
	exit(EXIT_SUCCESS);
}

static void	free_all(t_sort *main)
{
	if (main)
	{
		stack_clear(&(main -> stack_a), free);
		stack_clear(&(main -> stack_b), free);
		if (main -> way)
		{
			ft_lstclear(&(main -> way -> list), free);
			free(main -> way);
		}
		free(main);
	}
}
