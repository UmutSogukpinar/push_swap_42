/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umut <umut@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:38:00 by umut              #+#    #+#             */
/*   Updated: 2024/12/07 00:26:22 by umut             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	push(t_list **source, t_list **target)
{
	t_list	*source_head;
	t_list	*new_head;

	if (!(source && *source))
		return ;
	source_head = *source;
	new_head = (*source)->next;
	*source = new_head;
	source_head->next = NULL;
	ft_lstadd_front(target, source_head);
}

void	swap(t_list **list)
{
	t_list	*first_node;
	t_list	*second_node;

	if (ft_lstsize(*list) <= 1)
		return ;
	first_node = *list;
	second_node = first_node -> next;
	first_node -> next = second_node -> next;
	second_node -> next = first_node;
	*list = second_node;
}

void	rotate(t_list **list)
{
	t_list	*first_node;
	t_list	*second_node;
	t_list	*last_node;

	if (ft_lstsize(*list) <= 1)
		return ;
	first_node = *list;
	second_node = first_node -> next;
	last_node = *list;
	while (last_node -> next)
		last_node = last_node -> next;
	*list = second_node;
	last_node -> next = first_node;
	first_node -> next = NULL;
}

//int main()
//{
//	t_list *stack_a;
//	t_list *stack_b;

//	t_list *node1 = ft_lstnew(ft_strdup("node 1"));
//	t_list *node2 = ft_lstnew(ft_strdup("node 2"));
//	t_list *node3 = ft_lstnew(ft_strdup("node 3"));

//	ft_lstadd_back(&stack_a, node1);
//	ft_lstadd_back(&stack_a, node2);
//	ft_lstadd_back(&stack_a, node3);

//	if (!stack_a)
//	{
//		ft_printf("stack_a boş.\n");
//		return 0;
//	}
//	ft_printf("stack_a içeriği:\n");
//	t_list *current_a = stack_a;
//	while (current_a)
//	{
//		ft_printf("%s\n", (char *)current_a->content);
//		current_a = current_a->next;
//	}

//	rotate(&stack_a);

//	current_a = stack_a;

//	ft_printf("stack_a içeriği after push:\n");

//	while (current_a)
//	{
//		ft_printf("%s\n", (char *)current_a->content);
//		current_a = current_a->next;
//	}

	//current_a = stack_b;

	//ft_printf("stack_b içeriği after push:\n");

	//while (current_a)
	//{
	//	ft_printf("%s\n", (char *)current_a->content);
	//	current_a = current_a->next;
	//}
//}