/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:32:25 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:35:43 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	sort_2_elements_asc(t_sort *sort);
static void	sort_2_elements_desc(t_sort *sort);

void	sort_3_elements_asc(t_sort *sort)
{
	t_stack	*stack_a;
	int		first;
	int		second;
	int		third;

	if (!sort)
		return ;
	stack_a = sort->stack_a;
	first = stack_a->value;
	second = stack_a->next->value;
	third = stack_a->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(sort);
	else if (first > second && second > third)
		(swap_a(sort), reverse_rotate_a(sort));
	else if (first > second && second < third && first > third)
		rotate_a(sort);
	else if (first < second && second > third && first < third)
		(swap_a(sort), rotate_a(sort));
	else if (first < second && second > third && first > third)
		reverse_rotate_a(sort);
}

void	sort_2_elements(t_sort *sort, int mode)
{
	if (!sort)
		return ;
	if (mode == 1)
		sort_2_elements_asc(sort);
	else if (mode == 2)
		sort_2_elements_desc(sort);
}

static void	sort_2_elements_asc(t_sort *sort)
{
	t_stack	*sample;

	if (!sort)
		return ;
	sample = sort->stack_a;
	if (!sample || !sample->next)
		return ;
	if (sample->value > sample->next->value)
		swap_a(sort);
}

static void	sort_2_elements_desc(t_sort *sort)
{
	t_stack	*sample;

	if (!sort)
		return ;
	sample = sort->stack_b;
	if (!sample || !sample->next)
		return ;
	if (sample->value < sample->next->value)
		swap_b(sort);
}
