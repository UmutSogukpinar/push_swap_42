/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:40:42 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/20 19:47:38 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "libft.h"

typedef struct s_bonus
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*execution_list;
}			t_bonus;

void		exit_error(t_bonus *bonus);
void		exit_default(t_bonus *bonus);
void		create_execution_list(t_bonus *bonus);
void		execute_list(t_bonus *bonus);
void		list_update_bonus(t_bonus *bonus, t_list **list, void *content);
void		check_duplicate_bonus(t_bonus *bonus);
int			last_checks(t_bonus *bonus);

int			count_dd_array_elements_bonus(char **array);
int			*create_int_ptr_bonus(char *str);
long		atoi_long_bonus(char *str);
int			is_in_bound_bonus(long number);
int			is_number_bonus(char *str);
int			is_command(char *str);
int			is_equal(char *s1, char *s2);
int			is_list_sorted(t_list *list);
int			is_numbers_equal_bonus(int *one, int *two);

void		push_bonus(t_list **source, t_list **target);
void		swap_bonus(t_list **stack);
void		rotate_bonus(t_list **stack);
void		reverse_rotate_bonus(t_list **stack);

void		push_a_bonus(t_bonus *bonus);
void		push_b_bonus(t_bonus *bonus);
void		swap_a_bonus(t_bonus *bonus);
void		swap_b_bonus(t_bonus *bonus);
void		swap_both_bonus(t_bonus *bonus);
void		rotate_a_bonus(t_bonus *bonus);
void		rotate_b_bonus(t_bonus *bonus);
void		rotate_both_bonus(t_bonus *bonus);
void		reverse_rotate_a_bonus(t_bonus *bonus);
void		reverse_rotate_b_bonus(t_bonus *bonus);
void		reverse_rotate_both_bonus(t_bonus *bonus);

#endif
