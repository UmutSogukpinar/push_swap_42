/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:28:43 by usogukpi          #+#    #+#             */
/*   Updated: 2025/04/22 15:30:37 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "structures.h"

void	push_a(t_sort *main);
void	push_b(t_sort *main);

void	swap_a(t_sort *main);
void	swap_b(t_sort *main);
void	swap_both(t_sort *main);

void	rotate_a(t_sort *main);
void	rotate_b(t_sort *main);
void	rotate_both(t_sort *main);

void	reverse_rotate_a(t_sort *main);
void	reverse_rotate_b(t_sort *main);
void	reverse_rotate_both(t_sort *main);

#endif