/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:05:38 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/25 13:31:48 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	list_update_bonus(t_bonus *bonus, t_list **list, void *content)
{
	t_list	*new;

	if (!content)
		exit_error(bonus);
	new = ft_lstnew(content);
	if (!new)
		exit_error(bonus);
	ft_lstadd_back(list, new);
}

int	is_equal(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strlen(s1) == ft_strlen(s2) && ft_strncmp(s1, s2,
			ft_strlen(s1)) == 0);
}

int	is_command(char *str)
{
	if (str == NULL)
		return (0);
	return (is_equal(str, "sa\n") || is_equal(str, "sb\n") || is_equal(str, "ss\n")
		|| is_equal(str, "rr\n") || is_equal(str, "pa\n") || is_equal(str, "pb\n")
		|| is_equal(str, "ra\n") || is_equal(str, "rb\n") || is_equal(str, "rra\n")
		|| is_equal(str, "rrb\n") || is_equal(str, "rrr\n"));
}

int	is_numbers_equal_bonus(int *one, int *two)
{
	return (*one == *two);
}
