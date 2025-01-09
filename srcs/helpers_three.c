/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:41:37 by umut              #+#    #+#             */
/*   Updated: 2025/01/09 16:16:29 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_str_same(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2)
		&& ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
		return (1);
	else
		return (0);
}

int	count_dd_array_elements(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter] != NULL)
		counter++;
	return (counter);
}
