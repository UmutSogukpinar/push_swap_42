/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:29:36 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 23:33:40 by umut             ###   ########.fr       */
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
