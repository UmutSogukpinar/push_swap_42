/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usogukpi <usogukpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:28:49 by usogukpi          #+#    #+#             */
/*   Updated: 2025/04/22 15:31:07 by usogukpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/*
 * Simple boolean enum for the boolean statement.
 */
typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

/*
 * Holds the number of operations required to move a specific element.
 * Each field corresponds to a stack operation (e.g., ra = rotate_a count).
 */
typedef struct s_way
{
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_way;

/*
 * Node of a stack (used for both stack_a and stack_b).
 * 'value' is the original number, 'index' is its sorted position.
 */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/*
 * Main structure holding both stacks and the current best move path (t_way).
 */
typedef struct s_sort
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_way			*way;
}					t_sort;

#endif