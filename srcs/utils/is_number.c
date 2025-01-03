/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:16:22 by umut              #+#    #+#             */
/*   Updated: 2024/12/17 23:04:39 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit((int) str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*create_int_ptr(char *str)
{
	int	*new_value;

	if (!ft_is_number(str))
		return (NULL);
	new_value = malloc(sizeof(int));
	if (!new_value)
		return (NULL);
	*new_value = ft_atoi(str);
	return (new_value);
}
