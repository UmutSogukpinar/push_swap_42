/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:21:07 by umut              #+#    #+#             */
/*   Updated: 2025/01/04 00:28:52 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "sort.h"

void	stack_b_setup(t_list **src, t_list **target)
{
	push_a(src, target);
	push_a(src, target);
	push_a(src, target);
	sort_for_three_reverse(target);
}
