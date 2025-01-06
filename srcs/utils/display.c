/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:26:58 by umut              #+#    #+#             */
/*   Updated: 2025/01/06 20:31:06 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "ft_printf.h"

void	ft_display_str_list(t_list *list)
{
	int	i;

	i = 0;
	while (list != NULL)
	{
		if (list->content)
			ft_printf("Node %d: %s\n", i, (char *)(list->content));
		else
			ft_printf("Node %d: (null)\n", i);
		list = list->next;
		i++;
	}
}