/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:16:50 by umut              #+#    #+#             */
/*   Updated: 2025/01/06 20:03:12 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "operations.h"
#include "ft_printf.h"

void	sort_default(t_sort *sort_struct)
{
	t_way	*opt;
	int		is_problem;

	stack_b_setup(&(sort_struct -> stack_a), &(sort_struct -> stack_b));
	while (ft_lstsize(sort_struct -> stack_a) > 3)
	{
		opt = init_optimum_struc();
		if (!opt)
			shut_program(&(sort_struct -> stack_a), &(sort_struct -> stack_b));
		sort_struct -> way = opt;
		is_problem = reverse_sort(sort_struct);
		if (is_problem != 0)
			shut_program(&(sort_struct -> stack_a), &(sort_struct -> stack_b));
		free(opt);
	}
	ft_printf("stack_b:\n");
	ft_display_int_list(sort_struct -> stack_b);
	stack_a_setup(&(sort_struct -> stack_a));
	resend_to_a(sort_struct);
	while (!is_sorted(sort_struct -> stack_a))
		reverse_rotate_a(&(sort_struct -> stack_a));
}
