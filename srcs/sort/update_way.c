/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:44:54 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:44:55 by usogukpi         ###   ########.fr       */
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
