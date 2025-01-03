/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:36:22 by umut              #+#    #+#             */
/*   Updated: 2025/01/03 23:30:43 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

typedef struct s_optimum_way
{
	int		move_num;
	char	**move_array;
}	t_optimum_way;

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

#endif