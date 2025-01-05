/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:36:22 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 11:32:25 by umut             ###   ########.fr       */
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

void	shut_program(t_list **stack_a, t_list **stack_b);

int		is_sorted(t_list *list);
int		is_sorted_reverse(t_list *list);

void	sort(t_list **stack_a, t_list **stack_b);

void	sort_for_two(t_list **stack);
void	sort_for_three(t_list **stack);
void	sort_for_three_reverse(t_list **stack);
void	sort_default(t_list **stack_a, t_list **stack_b);

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

int		update_way(t_way *opt, t_list **stack_a, t_list **stack_b);

void	stack_b_setup(t_list **src, t_list **target);
void	stack_a_setup(t_list **stack_a);

void	resend_to_a(t_list **stack_a, t_list **stack_b);
void	resend_the_biggest(t_list **stack_a, t_list **stack_b);
void	resend_the_smallest(t_list **stack_a, t_list **stack_b);
void	resend_middles(t_list **stack_a, t_list **stack_b);
void	resend_for_lower(t_list **stack_a, t_list **stack_b);
void	resend_for_upper(t_list **stack_a, t_list **stack_b);
void	resend_for_upper_utils(t_list **stack_a, t_list **stack_b);
#endif