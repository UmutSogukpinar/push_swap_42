/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:33:20 by umut              #+#    #+#             */
/*   Updated: 2025/01/03 23:49:10 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

t_optimum_way	*init_optimum_struc()
{
	t_optimum_way	*structure;
	char			**array;

	structure = malloc(sizeof(t_optimum_way));
	if (!structure)
		return (NULL);
	array = malloc(sizeof(char *));
	if (!array)
	{
		if (structure)
			free(structure);
		return (NULL);
	}
	array[0] = NULL;
	structure -> move_num = 2147483647;
	structure -> move_array = array;
	return (structure);
}
