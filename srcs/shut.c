/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:26:38 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/25 16:26:41 by usogukpi         ###   ########.fr       */
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

void	free_way(t_way *way)
{
	if (way)
	{
		ft_lstclear(&(way -> list), free);
		free(way);
	}
}
