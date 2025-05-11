#include "push_swap.h"
#include "stdlib.h"

int	main(int argc, char **args)
{
	t_sort	*sort;
	char	**modified_args;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (are_args_nul(argc, args))
		return (ERROR_EXIT_CODE);
	modified_args = modify_args(argc, args);
	if (!are_args_proper(modified_args))
	{
		free_2d_char_array(modified_args);
		return (ERROR_EXIT_CODE);
	}
	sort = init_sort_struct(modified_args);
	if (!check_duplicates(sort))
	{
		shut_program_error(sort, ERROR_MSG);
	}
	if (is_sorted(sort->stack_a))
		return (shut_program_success(sort));
	else
		sort_main(sort);
	shut_program_success(sort);
	return (EXIT_SUCCESS);
}
