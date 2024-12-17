/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:01:18 by umut              #+#    #+#             */
/*   Updated: 2024/12/17 23:04:21 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "controls.h"
#include "sort.h"

t_list	*init_stack(char **args)
{
	int		i;
	int		*new_value;
	t_list	*new_node;
	t_list	*new_stack;

	i = 0;
	new_stack = NULL;
	while (args[++i])
	{
		new_value = create_int_ptr(args[i]);
		if (!new_value)
		{
			ft_lstclear(&new_stack, free);
			return (NULL);
		}
		new_node = ft_lstnew(new_value);
		if (!new_node)
		{
			free(new_value);
			ft_lstclear(&new_stack, free);
			return (NULL);
		}
		ft_lstadd_back(&new_stack, new_node);
	}
	return (new_stack);
}

int	main(int arg_number, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (arg_number <= 1)
		return (0);
	stack_a = init_stack(args);
	stack_b = NULL;
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_display_int_list(stack_a);
	if (!is_sorted(stack_a))
		sort(&stack_a, &stack_b);
	ft_display_int_list(stack_a);
	ft_lstclear(&stack_a, free);
	return (0);
}
