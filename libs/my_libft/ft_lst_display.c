/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:33:07 by umut              #+#    #+#             */
/*   Updated: 2025/01/04 22:14:37 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_display_int_list(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (list->content)
			printf("Node %d: %d\n", i, *(int *)(list->content));
		else
			printf("Node %d: (null)\n", i);
		list = list->next;
		i++;
	}
}
