/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:27:03 by umut              #+#    #+#             */
/*   Updated: 2024/12/18 22:46:50 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "controls.h"
#include "operations.h"
#include "ft_printf.h"

void	sort_default(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		node_value;
	int		correct_index;
	int		stack_b_size;

	init_stack_b(stack_a, stack_b);
	sort_for_three_reverse(stack_b);
	temp = *stack_a;
	while (temp)
	{
		node_value = *(int *)temp -> content;
		correct_index = find_correct_index(node_value, *stack_b);
		stack_b_size = ft_lstsize(*stack_b);
		if (correct_index <= (stack_b_size / 2))
			sort_default_option_one(correct_index, stack_a, stack_b);
		else
			sort_default_option_two(correct_index, stack_a, stack_b);
		temp = *stack_a;
	}
	push_back(stack_a, stack_b);
}

void	sort_default_option_one(int index, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < index)
	{
		rotate_b(stack_b);
		i++;
	}
	push_b(stack_a, stack_b);
	while (0 < i)
	{
		reverse_rotate_b(stack_b);
		i--;
	}
}

void	sort_default_option_two(int index, t_list **stack_a, t_list **stack_b)
{
	int	number_rotate;
	int	number_rev_rotate;
	int	i;

	number_rev_rotate = ft_lstsize(*stack_b) - index;
	number_rotate = number_rev_rotate + 1;
	i = 0;
	while (i < number_rev_rotate)
	{
		reverse_rotate_b(stack_b);
		i++;
	}
	push_b(stack_a, stack_b);
	i = 0;
	while (i < number_rotate)
	{
		rotate_b(stack_b);
		i++;
	}
}

void	init_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		push_b(stack_a, stack_b);
		i++;
	}
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	int		stack_b_size;

	stack_b_size = ft_lstsize(*stack_b);
	while (stack_b_size > 0)
	{
		push_a(stack_b, stack_a);
		stack_b_size--;
	}
}