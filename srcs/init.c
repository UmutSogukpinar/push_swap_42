/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:19:45 by umut              #+#    #+#             */
/*   Updated: 2025/01/08 22:45:08 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

t_sort	*init_sort_struct(void)
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

void	utilized_main(t_sort *main, char **args, int arg_num)
{
	int		*value;
	int		i;
	char	**my_args;

	i = -1;
	if (arg_num == 2)
	{
		my_args = ft_split(args[1], ' ');
		while (++i < count_dd_array_elements(my_args))
		{
			value = create_int_ptr(my_args[i]);
			stack_update(main, value);
			free(my_args[i]);
		}
		free(my_args);
		return ;
	}
	i = 0;
	while (++i < arg_num)
	{
		value = create_int_ptr(args[i]);
		stack_update(main, value);
	}
}

t_way	*init_way(void)
{
	t_way	*way;

	way = malloc(sizeof(t_way));
	if (!way)
		return (NULL);
	way -> amount = 0;
	way -> list = NULL;
	return (way);
}

void	init_index_value(t_sort *main)
{
	t_stack	*temp_one;
	t_stack	*temp_two;
	int		value_one;
	int		value_two;
	int		counter;

	temp_one = main -> stack_a;
	while (temp_one)
	{
		value_one = *(int *)(temp_one -> content);
		temp_two = main -> stack_a;
		counter = 0;
		while (temp_two)
		{
			value_two = *(int *)(temp_two -> content);
			if (value_one > value_two)
				counter++;
			temp_two = temp_two -> next;
		}
		temp_one -> index = counter;
		temp_one = temp_one -> next;
	}
}
