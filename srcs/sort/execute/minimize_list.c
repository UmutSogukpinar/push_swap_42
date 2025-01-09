/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:03:05 by umut              #+#    #+#             */
/*   Updated: 2025/01/09 10:54:15 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	minimize_list(t_list **list)
{
	minimize_rotate(list);
	minimize_reverese_rotate(list);
	//minimize_swap(list);
}

static void	remove_command_helper(t_list **list, char *content);

void	remove_command(t_list **list, char *content)
{
	t_list	*temp;
	char	*str;

	if (!list | !(*list))
		return ;
	str = (char *)((*list) -> content);
	if (ft_strncmp(str, content, ft_strlen(content)) == 0
		&& ft_strlen(str) == ft_strlen(content))
	{
		temp = *list;
		*list = (*list) -> next;
		free(temp);
		return ;
	}
	remove_command_helper(list, content);
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
		if (ft_strncmp(str, command, ft_strlen(command)) == 0
			&& ft_strlen(str) == ft_strlen(command))
		{
			temp = current -> next;
			current -> next = current -> next -> next;
			free(temp);
			return ;	
		}
		current = current -> next;
	}
}
