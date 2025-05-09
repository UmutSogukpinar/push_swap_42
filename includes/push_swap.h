/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:28:46 by usogukpi          #+#    #+#             */
/*   Updated: 2025/04/22 15:29:30 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "structures.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define SPACE_S " "
# define SPACE_C ' '

# define ERROR_MSG "Error"
# define ERROR_EXIT_CODE 255

# define B_TO_A 1
# define A_TO_B 2

t_sort	*init_sort_struct(char **args);

void	shut_program_error(t_sort *sort, char *message);
int		shut_program_success(t_sort *sort);

void	sort_main(t_sort *sort);
void	sort_2_elements(t_sort *sort, int mode);
void	sort_3_elements_asc(t_sort *sort);

void	fill_way(t_way *temp_way, t_sort *main, int index, int mode);
void	create_way(t_sort *main, int mode);
void	execute_way(t_sort *main);
int		get_operations_amount(t_way *way);

int		get_position(t_stack *stack, int index);
int		get_biggest_smaller_index(t_stack *stack, int given_index);
int		get_smallest_bigger_index(t_stack *stack, int given_index);
int		get_smallest_index(t_sort *main, t_stack *stack);
int		get_biggest_index(t_sort *main, t_stack *stack);

void	free_2d_char_array(char **array);
t_bool	are_strs_equal(char *s1, char *s2);

char	**modify_args(int argc, char **args);
t_bool	are_args_proper(char **args);
t_bool	are_args_nul(int argc, char **args);

void	stack_a_update(t_sort *main, char **args, char *value);
void	stack_add_front(t_stack **stack, t_stack *new_stack);
int		stack_size(t_stack *stack);

t_bool	is_sorted(t_stack *stack);
t_bool	is_partly_sorted(t_stack *stack);

#endif