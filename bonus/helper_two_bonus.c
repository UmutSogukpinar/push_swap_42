/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:03:23 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/20 17:53:31 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_number_bonus(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	atoi_long_bonus(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (num * sign);
}

int	is_in_bound_bonus(long number)
{
	if (number > 2147483647 || number < -2147483648)
		return (0);
	else
		return (1);
}

int	count_dd_array_elements_bonus(char **array)
{
	int	counter;

	counter = 0;
	while (array[counter] != NULL)
		counter++;
	return (counter);
}

int	*create_int_ptr_bonus(char *str)
{
	int	*number;

	if (!is_number_bonus(str))
		return (NULL);
	if (!is_in_bound_bonus(atoi_long_bonus(str)))
		return (NULL);
	number = malloc(sizeof(int));
	if (!number)
		return (NULL);
	*number = ft_atoi(str);
	return (number);
}
