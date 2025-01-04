/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tail.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:27:07 by umut              #+#    #+#             */
/*   Updated: 2025/01/04 20:29:13 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_list	*get_tail(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}
