/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:47:23 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:27:03 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structures.h"

static void	free_push_swap(t_sort *sort);
static void	stack_clear(t_stack **stack);

void	shut_program_error(t_sort *sort, char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	free_push_swap(sort);
	exit(255);
}

int	shut_program_success(t_sort *sort)
{
	free_push_swap(sort);
	return (EXIT_SUCCESS);
}

static void	free_push_swap(t_sort *sort)
{
	if (!sort)
		return ;
	if (sort->stack_a)
		stack_clear(&sort->stack_a);
	if (sort->stack_b)
		stack_clear(&sort->stack_b);
	free(sort->way);
	free(sort);
}

static void	stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
