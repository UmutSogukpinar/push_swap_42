/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:54:42 by usogukpi          #+#    #+#             */
/*   Updated: 2025/05/06 15:26:18 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "gnl/get_next_line.h"
#include "libft.h"
#include "push_swap.h"

static t_bool	is_instruction_valid(char *instruction);
static void		execute_all_instructions(t_sort *sort);
static void		execute_instruction(t_sort *sort, char *instruction);
static void		execute_instruction2(t_sort *sort, char *instruction);

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
	execute_all_instructions(sort);
	if (is_sorted(sort->stack_a) && stack_size(sort->stack_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	shut_program_success(sort);
	return (EXIT_SUCCESS);
}

static void	execute_all_instructions(t_sort *sort)
{
	char	*line;
	char	*instruction;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		instruction = ft_strtrim(line, "\n");
		free(line);
		if (!instruction)
			shut_program_error(sort, "Alloc error on execute_instructions()");
		if (is_instruction_valid(instruction))
			execute_instruction(sort, instruction);
		else
		{
			clear_gnl();
			free(instruction);
			shut_program_error(sort, "Error");
		}
		free(instruction);
	}
}

static void	execute_instruction(t_sort *sort, char *instruction)
{
	if (are_strs_equal(instruction, RA))
		rotate(&sort->stack_a);
	else if (are_strs_equal(instruction, RB))
		rotate(&sort->stack_b);
	else if (are_strs_equal(instruction, RR))
	{
		rotate(&sort->stack_a);
		rotate(&sort->stack_b);
	}
	else if (are_strs_equal(instruction, RRA))
		reverse_rotate(&sort->stack_a);
	else if (are_strs_equal(instruction, RRB))
		reverse_rotate(&sort->stack_b);
	else if (are_strs_equal(instruction, RRR))
	{
		reverse_rotate(&sort->stack_a);
		reverse_rotate(&sort->stack_b);
	}
	else
		execute_instruction2(sort, instruction);
}

static void	execute_instruction2(t_sort *sort, char *instruction)
{
	if (are_strs_equal(instruction, SA))
		swap(&sort->stack_a);
	else if (are_strs_equal(instruction, SB))
		swap(&sort->stack_b);
	else if (are_strs_equal(instruction, SS))
	{
		swap(&sort->stack_a);
		swap(&sort->stack_b);
	}
	else if (are_strs_equal(instruction, PA))
		push(&sort->stack_b, &sort->stack_a);
	else if (are_strs_equal(instruction, PB))
		push(&sort->stack_a, &sort->stack_b);
}

static t_bool	is_instruction_valid(char *instruction)
{
	if (are_strs_equal(instruction, RA) || are_strs_equal(instruction, RB)
		|| are_strs_equal(instruction, RR) || are_strs_equal(instruction, RRA)
		|| are_strs_equal(instruction, RRB) || are_strs_equal(instruction, RRR)
		|| are_strs_equal(instruction, SA) || are_strs_equal(instruction, SB)
		|| are_strs_equal(instruction, SS) || are_strs_equal(instruction, PA)
		|| are_strs_equal(instruction, PB))
	{
		return (TRUE);
	}
	return (FALSE);
}
