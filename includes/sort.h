/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:21 by umut              #+#    #+#             */
/*   Updated: 2025/01/09 18:07:40 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

typedef struct s_stack
{
	int				index;
	void			*content;
	struct s_stack	*next;

}	t_stack;

typedef struct s_way
{
	int		amount;
	t_list	*list;

}	t_way;

typedef struct s_sort
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_way	*way;

}	t_sort;

void	shut_program_error(t_sort *main);
void	shut_program_default(t_sort *main);
void	free_way(t_way *way);
void	update_way(t_sort *main, t_way *temp);

t_sort	*init_sort_struct(void);
void	init_index_value(t_sort *main);
t_way	*init_way(void);
void	utilized_main(t_sort *main, char **args, int arg_num);

void	sort(t_sort *main);

void	sort_two_asc(t_sort *main, char *type);
void	sort_three_asc(t_sort *main);

void	sort_default(t_sort *main);
void	setup_b(t_sort *main);
void	create_way(t_sort *main);
t_way	*create_alternate_way(t_sort *main, int index);
void	alternate_way(t_sort *main, t_way *temp_way, int index);
void	optimum_way_utils_one(t_sort *main, t_way *alternate, int index);
void	optimum_way_utils_two(t_sort *main, t_way *alternate, int index);
void	optimum_way_utils_zero(t_sort *main, t_way *alternate, int index);
void	final_touch(t_sort *main);

void	execute(t_sort *main);
void	execute_commands(t_sort *main, char *command);
void	remove_command(t_list **list, char *command);
void	minimize_list(t_list **list);
void	minimize_rotate(t_list **list);
void	minimize_reverese_rotate(t_list	**list);
void	minimize_swap(t_list **list);

void	resend(t_sort *main);
void	create_resend_way(t_sort *main);
t_way	*create_alternate_resend_way(t_sort *main, int index);
void	alternate_resend(t_sort *main, t_way *alternate, int index);
void	opt_rsnd_utils_one(t_sort *main, t_way *alternate, int index);
void	opt_rsnd_utils_two(t_sort *main, t_way *alternate, int index);
void	opt_rsnd_utils_zero(t_sort *main, t_way *alternate, int index);
void	final_touch_resend(t_sort *main);

int		is_sorted(t_stack *stack);
int		is_number(char *str);
int		is_biggest(t_stack *stack, int index);
int		is_smallest(t_stack *stack, int index);
int		is_in_upper_part(t_stack *stack, int pos);
int		find_pos(t_stack *stack, int index);
int		find_smallest_bigger_index(t_stack *stack, int index);
int		find_biggest_smaller_index(t_stack *stack, int index);
int		*create_int_ptr(char *str);
int		find_biggest_pos(t_stack *stack);
int		find_smallest_pos(t_stack *stack);
int		count_dd_array_elements(char **array);
int		is_str_same(char *s1, char *s2);
void	check_duplicate(t_sort *main);
long	atoi_long(char	*str);
int		is_in_bound(long number);

#endif