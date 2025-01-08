/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:16:20 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 15:33:14 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "operations.h"

void	sort_default(t_sort *main)
{
	setup_b(main);
	//while (stack_size(main -> stack_a) > 3)
	//{
		
	//}
	sort(main);
	resend(main);
}

void	setup_b(t_sort *main)
{
	push_b(main);
	push_b(main);
	sort_two_asc(main, "b");
}
