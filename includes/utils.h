/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 23:33:02 by umut              #+#    #+#             */
/*   Updated: 2025/01/03 23:58:46 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "libft.h"
# include "sort.h"

int				ft_is_number(char *str);
int				*create_int_ptr(char *str);

int				find_correct_index(int number, t_list *stack);

t_optimum_way	*init_optimum_struc();

#endif