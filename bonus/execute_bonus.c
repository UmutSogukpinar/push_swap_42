/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:50:13 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/21 12:08:26 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "get_next_line/get_next_line.h"

void	check_execution_list(t_bonus *bonus);
void	execute_command_bonus(t_bonus *bonus, char *command);

void	create_execution_list(t_bonus *bonus)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(0);
		if (!temp)
			break ;
		list_update_bonus(bonus, &(bonus->execution_list), temp);
	}
	check_execution_list(bonus);
}

void	check_execution_list(t_bonus *bonus)
{
	t_list	*temp;

	if (bonus)
	{
		temp = bonus->execution_list;
		while (temp)
		{
			if (!is_command(temp->content))
				exit_error(bonus);
			temp = temp->next;
		}
	}
}

void	execute_list(t_bonus *bonus)
{
	t_list	*temp;

	if (bonus)
	{
		temp = bonus->execution_list;
		while (temp)
		{
			execute_command_bonus(bonus, temp->content);
			temp = temp->next;
		}
	}
}

void	execute_command_bonus(t_bonus *bonus, char *command)
{
	if (is_equal(command, "pa\n"))
		push_a_bonus(bonus);
	else if (is_equal(command, "pb\n"))
		push_b_bonus(bonus);
	else if (is_equal(command, "sa\n"))
		swap_a_bonus(bonus);
	else if (is_equal(command, "sb\n"))
		swap_b_bonus(bonus);
	else if (is_equal(command, "ss\n"))
		swap_both_bonus(bonus);
	else if (is_equal(command, "ra\n"))
		rotate_a_bonus(bonus);
	else if (is_equal(command, "rb\n"))
		rotate_b_bonus(bonus);
	else if (is_equal(command, "rr\n"))
		rotate_both_bonus(bonus);
	else if (is_equal(command, "rra\n"))
		reverse_rotate_a_bonus(bonus);
	else if (is_equal(command, "rrb\n"))
		reverse_rotate_b_bonus(bonus);
	else if (is_equal(command, "rrr\n"))
		reverse_rotate_both_bonus(bonus);
	else
		exit_error(bonus);
}
