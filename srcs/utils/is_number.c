/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:16:22 by umut              #+#    #+#             */
/*   Updated: 2025/01/04 22:28:47 by umut             ###   ########.fr       */
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

int	is_in_middle(t_list *high, t_list *middle, t_list *low)
{
	if (!high || !middle || !low)
		return (-1);
	if ((*(int *)(high -> content)) > (*(int *)(middle -> content)))
	{
		if ((*(int *)(middle -> content)) > (*(int *)(low -> content)))
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}

int	is_biggest(t_list *stack_a, t_list *stack_b)
{
	int	b_value;
	int	a_value;

	if (!stack_b || !stack_a)
		return (0);
	b_value = (*(int *)(stack_b -> content));
	while (stack_a)
	{
		a_value = (*(int *)(stack_a -> content));
		if (a_value > b_value)
			return (0);
		stack_a = stack_a -> next;
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
