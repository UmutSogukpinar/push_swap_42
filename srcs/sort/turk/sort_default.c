/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:17:34 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 17:19:17 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "operations.h"

void	sort_default(t_sort *main)
{
	setup_b(main);
	while (stack_size(main -> stack_a) > 3)
	{
		create_way(main);
		execute(main);
		free_way(main -> way);
		main -> way = NULL;
	}
	final_touch(main);
	sort(main);
	resend(main);
}

void	setup_b(t_sort *main)
{
	push_b(main);
	push_b(main);
	sort_two_asc(main, "b");
}
