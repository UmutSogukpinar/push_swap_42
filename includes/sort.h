/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:36:22 by umut              #+#    #+#             */
/*   Updated: 2025/01/06 19:50:32 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

typedef struct s_way
{
	int		move_num;
	t_list	*move_list;
}	t_way;

typedef struct s_sort
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_way	*way;
}	t_sort;


void	shut_program(t_list **stack_a, t_list **stack_b);
void	free_way(t_way *temp);

int		is_sorted(t_list *list);
int		is_sorted_reverse(t_list *list);

void	sort(t_sort *sort_struct);

void	sort_for_two(t_list **stack);
void	sort_for_three(t_list **stack);
void	sort_for_three_reverse(t_list **stack);
void	sort_default(t_sort *sort_struct);

void	sort_three_option_one(t_list **list);
void	sort_three_option_two(t_list **list);
void	sort_three_option_three(t_list **list);
void	sort_three_option_four(t_list **list);
void	sort_three_option_five(t_list **list);

void	sort_three_reverse_option_one(t_list **stack);
void	sort_three_reverse_option_two(t_list **stack);
void	sort_three_reverse_option_three(t_list **stack);
void	sort_three_reverse_option_four(t_list **stack);
void	sort_three_reverse_option_five(t_list **stack);

int		reverse_sort(t_sort *s_strct);
void	execute_way(t_list *move_list, t_sort *s_strct);
void	cmd_exec(char *command, t_list **stack_a, t_list **stack_b);

int		find_way(t_sort *s_strct, int value);
int		find_way_helper_two(t_sort *s_strct, int index, t_way *temp);
int		find_way_helper_one(t_sort *s_strct, int index, t_way *temp);
void	get_upper_head(t_way *temp, t_list *stack_a, int value);
void	update_way(t_sort *s_strct, t_way *temp);
void	init_temp_way(t_way *temp);
int		update_list(t_list **list, char *command);

void	stack_b_setup(t_list **src, t_list **target);
void	stack_a_setup(t_list **stack_a);

void	resend_to_a(t_sort *s_struct);

void	resend_the_biggest(t_list **stack_a, t_list **stack_b);
void	resend_smallest(t_list **stack_a, t_list **stack_b);

void	resend_middles(t_list **stack_a, t_list **stack_b);

void	resend_for_lower(t_list **stack_a, t_list **stack_b);
void	resend_for_lower_utils(t_list **stack_a, t_list **stack_b);

void	resend_for_upper(t_list **stack_a, t_list **stack_b);
void	resend_for_upper_utils(t_list **stack_a, t_list **stack_b);
#endif