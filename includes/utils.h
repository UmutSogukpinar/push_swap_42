/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:33:02 by umut              #+#    #+#             */
/*   Updated: 2025/01/05 02:41:57 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "sort.h"

int		ft_is_number(char *str);
int		*create_int_ptr(char *str);
int		is_biggest(t_list *stack_a, t_list *stack_b);
int		is_smallest(t_list *stack_a, t_list *stack_b);
int		find_correct_index(int number, t_list *stack);
int		is_in_lower_part(int number, t_list *stack);
t_list	*get_tail(t_list *stack);
t_way	*init_optimum_struc(void);

#endif