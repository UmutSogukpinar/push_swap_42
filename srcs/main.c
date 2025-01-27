/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:26:31 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/25 16:26:34 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	main(int arg_number, char **args)
{
	t_sort	*main;

	main = init_sort_struct();
	if (!main)
		shut_program_error(main);
	if (arg_number <= 1)
		shut_program_default(main);
	utilized_main(main, args, arg_number);
	check_duplicate(main);
	init_index_value(main);
	if (!is_sorted(main -> stack_a))
		sort(main);
	shut_program_default(main);
	return (0);
}
