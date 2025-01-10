/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:16:44 by umut              #+#    #+#             */
/*   Updated: 2025/01/09 16:14:29 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operations.h"
#include "ft_printf.h"

void	execute(t_sort *main)
{
	t_list	*cmd_list;
	char	*command;

	cmd_list = main -> way -> list;
	while (cmd_list)
	{
		command = (char *)(cmd_list -> content);
		execute_commands(main, command);
		cmd_list = cmd_list -> next;
	}
	//ft_printf("Execution completed\n");
}

void	execute_commands(t_sort *main, char *command)
{
	if (is_str_same(command, "pa"))
		push_a(main);
	else if (is_str_same(command, "pb"))
		push_b(main);
	else if (is_str_same(command, "sa"))
		swap_a(main);
	else if (is_str_same(command, "sb"))
		swap_b(main);
	else if (is_str_same(command, "ss"))
		swap_both(main);
	else if (is_str_same(command, "ra"))
		rotate_a(main);
	else if (is_str_same(command, "rb"))
		rotate_b(main);
	else if (is_str_same(command, "rr"))
		rotate_both(main);
	else if (is_str_same(command, "rra"))
		reverse_rotate_a(main);
	else if (is_str_same(command, "rrb"))
		reverse_rotate_b(main);
	else if (is_str_same(command, "rrr"))
		reverse_rotate_both(main);
}
