/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:40 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:44:41 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"

void	sort_two_asc(t_sort *main, char *type)
{
	t_stack	*head;
	t_stack	*tail;
	int		head_value;
	int		tail_value;

	head = NULL;
	if (ft_strncmp(type, "a", 1) == 0)
		head = (main -> stack_a);
	else if (ft_strncmp(type, "b", 1) == 0)
		head = (main -> stack_b);
	tail = head -> next;
	head_value = *(int *)head -> content;
	tail_value = *(int *)tail -> content;
	if (head_value <= tail_value)
		return ;
	if (ft_strncmp(type, "a", 1) == 0)
		swap_a(main);
	else if (ft_strncmp(type, "b", 1) == 0)
		swap_b(main);
}

void	sort_three_asc(t_sort *main)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(main -> stack_a -> content);
	b = *(int *)(main -> stack_a -> next -> content);
	c = *(int *)(main -> stack_a -> next -> next -> content);
	if (a > b && b < c && a < c)
		swap_a(main);
	else if (a > b && b > c && a > c)
	{
		swap_a(main);
		reverse_rotate_a(main);
	}
	else if (a > b && b < c && a > c)
		rotate_a(main);
	else if (a < b && b > c && a < c)
	{
		swap_a(main);
		rotate_a(main);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(main);
}
