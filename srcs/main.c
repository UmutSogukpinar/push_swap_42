/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:55:18 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 13:26:17 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"

int	main(int arg_number, char **args)
{
	t_sort	*main;

	(void) args;
	main = init_sort_struct();
	if (!main)
		shut_program_error(main);
	if (arg_number <= 1)
		shut_program_error(main);
	utilized_main(main, args, arg_number);
	display_int_stack(main -> stack_a);
	shut_program_default(main);
}
