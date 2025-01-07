/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:29:40 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 15:48:14 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "sort.h"

void	push_a(t_sort *main);
void	push_b(t_sort *main);

void	swap_a(t_sort *main);
void	swap_b(t_sort *main);

void	rotate_a(t_sort *main);
void	rotate_b(t_sort *main);
void	rotate_both(t_sort *main);

void	reverse_rotate_a(t_sort *main);
void	reverse_rotate_b(t_sort *main);
void	reverse_rotate_both(t_sort *main);

#endif