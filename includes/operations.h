/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:08:38 by umut              #+#    #+#             */
/*   Updated: 2024/12/17 20:58:58 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "actions.h"

void	push_a(t_list **source, t_list **target);
void	push_b(t_list **source, t_list **target);

void	swap_a(t_list **list);
//void	swap_b(t_list **list);
//void	swap_both(t_list **list_one, t_list **list_two);

void	rotate_a(t_list **list);
void	rotate_b(t_list **list);
void	rotate_both(t_list **list_one, t_list **list_two);

void	reverse_rotate_a(t_list **list);
void	reverse_rotate_b(t_list **list);
void	reverse_rotate_both(t_list **list_one, t_list **list_two);

#endif
