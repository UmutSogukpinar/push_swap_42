/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:43:51 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:28:49 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static char	*concat_all_args(int argc, char **args);
static char	*append_arg(char *head, char *added);

char	**modify_args(int argc, char **args)
{
	char	**modified_args;
	char	*head;

	head = concat_all_args(argc, args);
	modified_args = ft_split(head, SPACE_C);
	free(head);
	if (!modified_args)
		shut_program_error(NULL, "Alloc error on modify_args");
	return (modified_args);
}

static char	*concat_all_args(int argc, char **args)
{
	char	*head;
	int		i;

	i = 2;
	head = ft_strdup(args[1]);
	if (!head)
		shut_program_error(NULL, "Alloc error on concat_all_args");
	while (i < argc)
	{
		head = append_arg(head, args[i]);
		i++;
	}
	return (head);
}

static char	*append_arg(char *head, char *added)
{
	char	*temp;

	temp = ft_strjoin(head, SPACE_S);
	free(head);
	if (!temp)
		shut_program_error(NULL, "Alloc error on append_arg");
	head = temp;
	temp = ft_strjoin(head, added);
	free(head);
	if (!temp)
		shut_program_error(NULL, "Alloc error on append_arg");
	head = temp;
	return (head);
}
