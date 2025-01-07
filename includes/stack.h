/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:46:22 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:48:08 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "sort.h"

t_stack	*create_node(void *content);
void	stack_add_back(t_stack **stack, t_stack *new_stack);
void	stack_add_front(t_stack **stack, t_stack *new_stack);
void	stack_update(t_sort *main, int *value);
void	stack_clear(t_stack **stack, void (*del)(void *));
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);

void	ft_display_str_list(t_stack *stack);
void	display_int_stack(t_stack *stack);

#endif