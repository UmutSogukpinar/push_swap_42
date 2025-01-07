/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:57:21 by umut              #+#    #+#             */
/*   Updated: 2025/01/07 17:15:29 by umut             ###   ########.fr       */
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

t_sort	*init_sort_struct(void);
void	init_index_value(t_sort *main);
void	utilized_main(t_sort *main, char **args, int arg_num);

void	sort(t_sort *main);

void	sort_two_asc(t_sort *main, char *type);
void	sort_three_asc(t_sort *main);

void	sort_default(t_sort *main);
void	setup_b(t_sort *main);

int		is_sorted(t_stack *stack);
int		is_number(char *str);
int		*create_int_ptr(char *str);


#endif