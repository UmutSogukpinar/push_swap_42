#include "unistd.h"
#include "libft.h"
#include "push_swap.h"

static long		ato_long(char *arg);
static t_bool	is_integer(char *arg);

t_bool	are_args_proper(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) == 0 || ft_strlen(args[i]) > 11
			|| !is_integer(args[i]))
		{
			ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
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
			ft_putendl_fd("Allocation Error on are_args_nul()", STDERR_FILENO);
			return (TRUE);
		}
		if (ft_strlen(trimmed_arg) == 0)
		{
			free(trimmed_arg);
			ft_putendl_fd(ERROR_MSG, STDERR_FILENO);
			return (TRUE);
		}
		free(trimmed_arg);
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
