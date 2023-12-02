/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:55:00 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 14:14:08 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head, char stack_name, int print)
{
	int		temp;
	t_list	*first;
	t_list	*second;

	first = *head;
	second = first->next;
	if (!second || !first)
		return ;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	if (print)
		ft_printf("s%c\n", stack_name);
}

/*
	Push the first element of B to A
*/
void	push(t_list	**head_a, t_list **head_b, int push_a)
{
	t_list	*first_a;
	t_list	*first_b;

	first_a = *head_a;
	first_b = *head_b;
	if (!first_b)
		return ;
	*head_b = first_b->next;
	ft_lstadd_front(head_a, first_b);
	if (push_a == 1)
		ft_printf("pa\n");
	else if (!push_a)
		ft_printf("pb\n");
}

void	rotate(t_list	**head, char stack_name, int print)
{
	t_list	*last;

	if (!*head)
		return ;
	last = ft_lstlast(*head);
	last->next = *head;
	*head = (*head)->next;
	last->next->next = NULL;
	if (print)
		ft_printf("r%c\n", stack_name);
}

void	reverse_rotate(t_list **head, char stack_name, int print)
{
	t_list	*last;
	t_list	*before_last;

	if (!*head || !(*head)->next)
		return ;
	before_last = *head;
	last = before_last->next;
	while (last->next)
	{
		before_last = before_last->next;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *head;
	*head = last;
	if (print)
		ft_printf("rr%c\n", stack_name);
}
