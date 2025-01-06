/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:38:08 by umut              #+#    #+#             */
/*   Updated: 2025/01/06 20:54:36 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "ft_printf.h"

void	execute_way(t_list *move_list, t_sort *s_strct)
{
	t_list	*temp;
	char	*command;

	temp = move_list;
	while (temp)
	{
		command = (char *)(temp->content);
		cmd_exec(command, &(s_strct -> stack_a), &(s_strct -> stack_b));
		temp = temp -> next;
	}
}

void	cmd_exec(char *command, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(command, "pb", 2) == 0)
	{
		ft_printf("\n\npushed value is %d\n", (*(int *)(*stack_a) -> content));
		push_b(stack_a, stack_b);
	}
	else if (ft_strncmp(command, "rb", 2) == 0)
		rotate_b(stack_b);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		reverse_rotate_b(stack_b);
	else if (ft_strncmp(command, "ra", 2) == 0)
		rotate_a(stack_a);
	else if (ft_strncmp(command, "rra", 3) == 0)
		reverse_rotate_a(stack_a);
}