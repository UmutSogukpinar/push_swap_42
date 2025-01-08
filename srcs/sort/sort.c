/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:38:43 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 15:42:50 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	sort(t_sort *main)
{
	if (stack_size(main -> stack_a) == 2)
		sort_two_asc(main, "a");
	else if (stack_size(main -> stack_a) == 3)
		sort_three_asc(main);
	else if (stack_size(main -> stack_a) >= 4)
		sort_default(main);
}
