/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:29:13 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 16:50:01 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	update_way(t_sort *main, t_way *temp)
{
	if (main -> way == NULL)
		main -> way = temp;
	else
	{
		if ((main -> way -> amount) <= (temp -> amount))
			free_way(temp);
		else
		{
			free_way(main -> way);
			main -> way = temp;
		}
	}
}
