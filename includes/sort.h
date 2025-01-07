/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:21 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 13:16:48 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "libft.h"

typedef struct s_stack
{
	int				index;
	void			*content;
	struct s_stack	*next;

}	t_stack;

typedef struct s_way
{
	int		amount;
	t_list	*list;

}	t_way;

typedef struct s_sort
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_way	*way;

}	t_sort;


void	shut_program_error(t_sort *main);
void	shut_program_default(t_sort *main);

t_sort	*init_sort_struct();
void	utilized_main(t_sort *main, char **args, int arg_num);

#endif