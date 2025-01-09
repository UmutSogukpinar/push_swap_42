/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:41:37 by umut              #+#    #+#             */
/*   Updated: 2025/01/09 16:24:19 by umut             ###   ########.fr       */
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

void	check_duplicate(t_sort *main)
{
	t_stack	*temp_one;
	t_stack	*temp_two;

	temp_one = main -> stack_a;
	while (temp_one -> next)
	{
		temp_two = temp_one -> next;
		while (temp_two)
		{
			if (is_str_same(temp_one -> content, temp_two -> content))
				shut_program_error(main);
			temp_two = temp_two -> next;
		}
		temp_one = temp_one -> next;
	}
}
