/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:53:04 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/23 15:07:43 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_str_same(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) == ft_strlen(s2) && ft_strncmp(s1, s2,
			ft_strlen(s1)) == 0)
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

void	check_duplicate(t_sort *main)
{
	t_stack	*temp_one;
	t_stack	*temp_two;

	if (!main || !main->stack_a)
		return ;
	temp_one = main->stack_a;
	while (temp_one)
	{
		temp_two = temp_one->next;
		while (temp_two)
		{
			if (temp_one->content && temp_two->content
				&& is_numbers_equal((int *)temp_one->content,
					(int *)temp_two->content))
				shut_program_error(main);
			temp_two = temp_two->next;
		}
		temp_one = temp_one->next;
	}
}

long	atoi_long(char *str)
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

int	is_in_bound(long number)
{
	if (number > 2147483647 || number < -2147483648)
		return (0);
	else
		return (1);
}
