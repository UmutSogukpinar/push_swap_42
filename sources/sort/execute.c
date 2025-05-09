/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:08 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:35:21 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "operations.h"

static void	execute_opt(void (*op)(t_sort *), t_sort *main, int times);

void	execute_way(t_sort *main)
{
	t_way	*way;

	way = main->way;
	if (!way)
		return ;
	execute_opt(rotate_b, main, way->rb);
	execute_opt(reverse_rotate_a, main, way->rra);
	execute_opt(reverse_rotate_b, main, way->rrb);
	execute_opt(rotate_a, main, way->ra);
	execute_opt(rotate_both, main, way->rr);
	execute_opt(reverse_rotate_both, main, way->rrr);
	execute_opt(push_a, main, way->pa);
	execute_opt(push_b, main, way->pb);
	free(way);
	main->way = NULL;
}

static void	execute_opt(void (*opt)(t_sort *), t_sort *main, int times)
{
	int	i;

	if (!opt || !main || times <= 0)
	{
		return ;
	}
	i = -1;
	while (++i < times)
		opt(main);
}
