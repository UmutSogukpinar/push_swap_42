/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:19:45 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 13:25:43 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

t_sort	*init_sort_struct()
{
	t_sort	*main;

	main = malloc(sizeof(t_sort));
	if (!main)
		return (NULL);
	main -> stack_a = NULL;
	main -> stack_b = NULL;
	main -> way = NULL;
	return (main);
}

int	*create_int_ptr(char *str);

void	utilized_main(t_sort *main, char **args, int arg_num)
{
	int		*value;
	int		i;

	i = 1;
	while (i < arg_num)
	{
		value = create_int_ptr(args[i]);
		stack_update(main, value);
		i++;
	}
}

int	is_number(char *str)
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
		if (!ft_isdigit((int) str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*create_int_ptr(char *str)
{
	int	*number;

	if (!is_number(str))
		return (NULL);
	number = malloc(sizeof(int));
	if (!number)
		return (NULL);
	*number = ft_atoi(str);
	return (number);
}
