/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:16:44 by umut              #+#    #+#             */
/*   Updated: 2025/01/09 10:52:10 by umut             ###   ########.fr       */
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
	if (ft_strncmp(command, "pa", 2) == 0)
		push_a(main);
	else if (ft_strncmp(command, "pb", 2) == 0)
		push_b(main);
	else if (ft_strncmp(command, "sa", 2) == 0)
		swap_a(main);
	else if (ft_strncmp(command, "sb", 2) == 0)
		swap_b(main);
	else if (ft_strncmp(command, "ss", 2) == 0)
		swap_both(main);
	else if (ft_strncmp(command, "ra", 2) == 0)
		rotate_a(main);
	else if (ft_strncmp(command, "rb", 2) == 0)
		rotate_b(main);
	else if (ft_strncmp(command, "rr", 2) == 0 && ft_strlen(command) == 2)
		rotate_both(main);
	else if (ft_strncmp(command, "rra", 3) == 0)
		reverse_rotate_a(main);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		reverse_rotate_b(main);
	else if (ft_strncmp(command, "rrr", 3) == 0)
		reverse_rotate_both(main);
}
