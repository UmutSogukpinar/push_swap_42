#include "push_swap.h"

int	main(int argc, char **args)
{
	//t_sort	*sort;
	char	**modified_args;

	if (argc < 2)
		return (EXIT_FAILURE);
	modified_args = modify_args(argc, args);
	if (!are_args_proper(modified_args))
		return (EXIT_FAILURE);
	
}