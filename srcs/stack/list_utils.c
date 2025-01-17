/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:25:32 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 17:25:33 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	list_update(t_sort *main, t_list **list, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		shut_program_error(main);
	ft_lstadd_back(list, new);
}
