/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:36:22 by umut              #+#    #+#             */
/*   Updated: 2024/12/17 23:50:58 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

int		is_sorted(t_list *list);
int		is_sorted_reverse(t_list *list);

void	sort(t_list **stack_a, t_list **stack_b);
void	sort_for_two(t_list **stack_a);
void	sort_for_three(t_list **stack_a, t_list **stack_b);

void	sort_three_option_one(t_list **list);
void	sort_three_option_sec(t_list **list);
void	sort_three_option_third(t_list **list);
void	sort_three_option_fourth(t_list **list);
void	sort_three_option_fifth(t_list **list);

#endif