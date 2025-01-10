/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:03:05 by umut              #+#    #+#             */
/*   Updated: 2025/01/09 16:12:11 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	minimize_list(t_list **list)
{
	minimize_rotate(list);
	minimize_reverese_rotate(list);
	//minimize_swap(list);
}

static void	remove_command_helper(t_list **list, char *command);

void	remove_command(t_list **list, char *command)
{
	t_list	*temp;
	char	*str;

	if (!list | !(*list))
		return ;
	str = (char *)((*list) -> content);
	if (is_str_same(str, command))
	{
		temp = *list;
		*list = (*list) -> next;
		free(temp -> content);
		free(temp);
		return ;
	}
	remove_command_helper(list, command);
}

static void	remove_command_helper(t_list **list, char *command)
{
	t_list	*current;
	t_list	*temp;
	char	*str;

	current = *list;
	while (current -> next != NULL)
	{
		str = current -> next -> content;
		if (is_str_same(str, command))
		{
			temp = current -> next;
			current -> next = current -> next -> next;
			free(temp -> content);
			free(temp);
			return ;	
		}
		current = current -> next;
	}
}
