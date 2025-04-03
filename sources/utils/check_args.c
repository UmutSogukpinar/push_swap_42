#include "push_swap.h"

static long	ato_long(char *arg);
static t_bool	are_strs_equal(char *s1, char *s2);
static t_bool	is_integer(char *arg);
static t_bool	is_duplicate(char **args, char *arg, int index);

/*
* This function checks if the arguments passed to the program are valid. 
*/
t_bool are_args_proper(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) == 0 || ft_strlen(args[i]) > 11
			|| !is_integer(args[i]) || is_duplicate(args, args[i], i))
		{
			ft_putendl_fd("Error", 2);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static t_bool	is_duplicate(char **args, char *arg, int index)
{
	int i;

	i = 1;
	while (i < index)
	{
		if (are_strs_equal(args[i], arg))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static t_bool are_strs_equal(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (FALSE);
	if (ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
		return (TRUE);
	return (FALSE);
}

/*// * This function checks if the argument that given as parameter is valid*/
static t_bool	is_integer(char *arg)
{
	long	num;
	int i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
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
