/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:36:22 by umut              #+#    #+#             */
/*   Updated: 2024/12/18 22:33:06 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

int		is_sorted(t_list *list);
int		is_sorted_reverse(t_list *list);

void	sort(t_list **stack_a, t_list **stack_b);

void	sort_default(t_list **stack_a, t_list **stack_b);
void	sort_default_option_one(int index, t_list **stack_a, t_list **stack_b);
void	sort_default_option_two(int index, t_list **stack_a, t_list **stack_b);

void	sort_for_two(t_list **stack);
void	sort_for_three(t_list **stack);
void	sort_for_three_reverse(t_list **stack);

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

void	init_stack_b(t_list **stack_a, t_list **stack_b);
void	push_back(t_list **stack_a, t_list **stack_b);

#endif