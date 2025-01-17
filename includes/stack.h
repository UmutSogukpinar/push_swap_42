/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:05:20 by usogukpi          #+#    #+#             */
/*   Updated: 2025/01/17 16:05:22 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "sort.h"

void	list_update(t_sort *main, t_list **list, void *content);

t_stack	*create_node(void *content);
void	stack_add_back(t_stack **stack, t_stack *new_stack);
void	stack_add_front(t_stack **stack, t_stack *new_stack);
void	stack_update(t_sort *main, void *value);
void	stack_clear(t_stack **stack, void (*del)(void *));
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);

void	ft_display_str_list(t_stack *stack);
void	display_int_stack(t_stack *stack);

#endif