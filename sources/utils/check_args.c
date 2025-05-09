/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:45:00 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 18:38:30 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static long		ato_long(char *arg);
static t_bool	is_integer(char *arg);
static t_bool	is_duplicate(char **args, char *arg, int index);

t_bool	are_args_proper(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) == 0 || ft_strlen(args[i]) > 11
			|| !is_integer(args[i]) || is_duplicate(args, args[i], i))
		{
			ft_putendl_fd(ERROR_MSG, 2);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	are_args_nul(int argc, char **args)
{
	int		i;
	char	*trimmed_arg;

	i = 1;
	while (i < argc)
	{
		trimmed_arg = ft_strtrim(args[i], SPACE_S);
		if (trimmed_arg == NULL)
		{
			ft_putendl_fd("Allocation Error on are_args_nul()", 2);
			return (TRUE);
		}
		if (ft_strlen(trimmed_arg) == 0)
		{
			free(trimmed_arg);
			ft_putendl_fd(ERROR_MSG, 2);
			return (TRUE);
		}
		free(trimmed_arg);
		i++;
	}
	return (FALSE);
}

static t_bool	is_duplicate(char **args, char *arg, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (are_strs_equal(args[i], arg))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static t_bool	is_integer(char *arg)
{
	long	num;
	int		i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
		if (!ft_isdigit(arg[i]))
			return (FALSE);
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		i++;
	}
	num = ato_long(arg);
	if (num > MAX_INT || num < MIN_INT)
		return (FALSE);
	return (TRUE);
}

/*
 * Converts a numeric string into a long value.
 * Handles optional '+' or '-' prefix.
 */
static long	ato_long(char *arg)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		num = num * 10 + (arg[i] - '0');
		i++;
	}
	if (arg[0] == '-')
		num *= -1;
	return (num);
}
