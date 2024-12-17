/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:08:12 by umut              #+#    #+#             */
/*   Updated: 2024/12/10 20:26:13 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "libft.h"

void	push(t_list **source, t_list **target);
void	swap(t_list **list);
void	rotate(t_list **list);
void	reverse_rotate(t_list **list);

#endif