/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:33:07 by umut              #+#    #+#             */
/*   Updated: 2024/12/17 19:34:44 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_display_int_list(t_list *list)
{
    int i = 0;
	while (list != NULL)
	{
		if (list->content)
			ft_printf("Node %d: %d\n", i, *(int *)(list->content));
		else
			ft_printf("Node %d: (null)\n", i);
		list = list->next;
		i++;
	}
}
