/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:38:43 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:52:24 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

void	sort(t_sort *main)
{
	if (stack_size(main -> stack_a) == 2)
		sort_for_two(main);
	//else if (ft_lstsize(main -> stack_a) == 3)
	//	sort_for_three(&(main -> stack_a));
	//else if (ft_lstsize(main -> stack_a) >= 4)
	//	sort_default(main);
}
