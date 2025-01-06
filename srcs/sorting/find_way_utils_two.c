/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way_utils_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:30:42 by umut              #+#    #+#             */
/*   Updated: 2025/01/06 19:51:34 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	init_temp_way(t_way *temp)
{
	temp -> move_num = 0;
	temp -> move_list = NULL;
}

void	free_way(t_way *temp)
{
	if (temp)
	{
		ft_lstclear(&(temp -> move_list), free);
		free(temp);
	}
}
