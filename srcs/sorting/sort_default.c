/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:16:50 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 18:44:01 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "operations.h"
#include "ft_printf.h"
void	sort_default(t_list **stack_a, t_list **stack_b)
{
	//t_way	*opt;
	//int		is_problem;

	stack_b_setup(stack_a, stack_b);
	//while (ft_lstsize(stack_a) > 3)
	//{
	//	opt = init_optimum_struc();
	//	if (!opt)
	//		shut_program(stack_a, stack_b);
	//	is_problem = update_way(opt, stack_a, stack_b);
	//	if (is_problem != 0)
	//		shut_program(stack_a, stack_b);
	//}
	stack_a_setup(stack_a);
	resend_to_a(stack_a, stack_b);
	while (!is_sorted(*stack_a))
		reverse_rotate_a(stack_a);
}
