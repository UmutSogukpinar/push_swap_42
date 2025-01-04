/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:33:20 by umut              #+#    #+#             */
/*   Updated: 2025/01/04 20:47:29 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "libft.h"

t_way	*init_optimum_struc(void)
{
	t_way	*structure;
	t_list	*list;

	structure = malloc(sizeof(t_way));
	if (!structure)
		return (NULL);
	list = NULL;
	structure -> move_num = 2147483647;
	structure -> move_list = list;
	return (structure);
}
