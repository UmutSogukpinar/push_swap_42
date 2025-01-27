/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:10:14 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/23 15:00:23 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "ft_printf.h"

t_bonus	*init_bonus(char **args, int arg_num);
void	init_stack_a(t_bonus *bonus, char **args, int arg_num);

int	main(int arg_num, char **args)
{
	t_bonus	*bonus;
	int		check;

	if (arg_num == 1)
		return (0);
	bonus = init_bonus(args, arg_num);
	check_duplicate_bonus(bonus);
	create_execution_list(bonus);
	execute_list(bonus);
	check = last_checks(bonus);
	if (check)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_default(bonus);
	return (0);
}

t_bonus	*init_bonus(char **args, int arg_num)
{
	t_bonus	*new;

	new = malloc(sizeof(t_bonus));
	if (!new)
		return (NULL);
	new->stack_b = NULL;
	new->execution_list = NULL;
	init_stack_a(new, args, arg_num);
	return (new);
}

void	init_stack_a(t_bonus *bonus, char **args, int arg_num)
{
	char	**my_args;
	int		i;
	int		*value;

	bonus->stack_a = NULL;
	i = -1;
	if (arg_num == 2)
	{
		my_args = ft_split(args[1], ' ');
		while (++i < count_dd_array_elements_bonus(my_args))
		{
			value = create_int_ptr_bonus(my_args[i]);
			list_update_bonus(bonus, &(bonus->stack_a), value);
			free(my_args[i]);
		}
		free(my_args);
		return ;
	}
	i = 0;
	while (++i < arg_num)
	{
		value = create_int_ptr_bonus(args[i]);
		list_update_bonus(bonus, &(bonus->stack_a), value);
	}
}
