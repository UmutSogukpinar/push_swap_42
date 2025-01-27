/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:06:26 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/20 15:14:47 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "ft_printf.h"
#include "libft.h"

void	free_all(t_bonus *bonus);

void	exit_default(t_bonus *bonus)
{
	free_all(bonus);
	exit(EXIT_SUCCESS);
}

void	exit_error(t_bonus *bonus)
{
	free_all(bonus);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	free_all(t_bonus *bonus)
{
	if (bonus)
	{
		ft_lstclear(&(bonus->stack_a), free);
		ft_lstclear(&(bonus->stack_b), free);
		ft_lstclear(&(bonus->execution_list), free);
		free(bonus);
	}
}
