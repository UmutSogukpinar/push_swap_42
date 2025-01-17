/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:45 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:44:46 by usogukpi         ###   ########.fr       */
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
