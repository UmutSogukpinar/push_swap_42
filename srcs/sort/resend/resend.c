/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:30:13 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 23:27:04 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	resend(t_sort *main)
{
	while (main -> stack_b)
	{
		create_resend_way(main);
	}
}

void	create_resend_way(t_sort *main)
{
	t_stack	*temp_b;
	t_way	*temp_way;

	temp_b = main -> stack_b;
	while (temp_b)
	{
		temp_way = create_alternate_resend_way(main, temp_b -> index);
		update_way(main, temp_way);
		temp_b = temp_b -> next;
	}
}

t_way	*create_alternate_resend_way(t_sort *main, int index)
{
	t_way	*temp_way;

	temp_way = init_way();
	if (!temp_way)
		shut_program_error(main);
	optimum_resend(main , temp_way, index);
}

void	update_resend_way(t_sort *main, t_way *temp)
{
	
}