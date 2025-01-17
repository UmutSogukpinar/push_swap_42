/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:00:40 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 17:00:41 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int	get_counter(t_list *list, char *command);
static int	choose_less(int a, int b);

void	minimize_rotate(t_list **list)
{
	int	ra_counter;
	int	rb_counter;
	int	process_amount;
	int	i;

	ra_counter = get_counter(*list, "ra");
	rb_counter = get_counter(*list, "rb");
	process_amount = choose_less(ra_counter, rb_counter);
	i = -1;
	while (++i < process_amount)
	{
		remove_command(list, "ra");
		remove_command(list, "rb");
	}
	i = -1;
	while (++i < process_amount)
		ft_lstadd_front(list, ft_lstnew(ft_strdup("rr")));
}

void	minimize_reverese_rotate(t_list	**list)
{
	int	ra_counter;
	int	rb_counter;
	int	process_amount;
	int	i;

	ra_counter = get_counter(*list, "rra");
	rb_counter = get_counter(*list, "rrb");
	process_amount = choose_less(ra_counter, rb_counter);
	i = -1;
	while (++i < process_amount)
	{
		remove_command(list, "rra");
		remove_command(list, "rrb");
	}
	i = -1;
	while (++i < process_amount)
		ft_lstadd_front(list, ft_lstnew(ft_strdup("rrr")));
}

void	minimize_swap(t_list **list)
{
	int	ra_counter;
	int	rb_counter;
	int	process_amount;
	int	i;

	ra_counter = get_counter(*list, "sa");
	rb_counter = get_counter(*list, "sb");
	process_amount = choose_less(ra_counter, rb_counter);
	i = -1;
	while (++i < process_amount)
	{
		remove_command(list, "sa");
		remove_command(list, "sb");
	}
	i = -1;
	while (++i < process_amount)
		ft_lstadd_front(list, ft_lstnew(ft_strdup("ss")));
}

static int	get_counter(t_list *list, char *command)
{
	int		counter;
	char	*content;

	counter = 0;
	while (list)
	{
		content = (char *)(list -> content);
		if (ft_strncmp(content, command, ft_strlen(command)) == 0
			&& ft_strlen(content) == ft_strlen(command))
		{
			counter++;
		}
		list = list -> next;
	}
	return (counter);
}

static int	choose_less(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}
