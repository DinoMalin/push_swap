/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:24:24 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 03:42:50 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target(t_list **head_a, t_list *node)
{
	t_list	*result;
	t_list	*first;

	first = *head_a;
	result = get_max(head_a);
	while (first)
	{
		if (first->content < result->content && first->content >= node->content)
			result = first;
		first = first->next;
	}
	node->target = result;
}

void	set_index(t_list **head)
{
	int		i;
	int		len;
	t_list	*first;

	i = 0;
	len = ft_lstsize(*head);
	first = *head;
	while (first)
	{
		first->index = i;
		if (i <= len / 2)
			first->top_half = TRUE;
		else
			first->top_half = FALSE;
		i++;
		first = first->next;
	}
}

void	set_targets(t_list **head_a, t_list **head_b)
{
	t_list	*first_b;

	first_b = *head_b;
	while (first_b)
	{
		get_target(head_a, first_b);
		first_b = first_b->next;
	}
}

void	set_prices(t_list **head_a, t_list **head_b)
{
	t_list	*first;
	int		size_a;
	int		size_b;

	first = *head_b;
	size_a = ft_lstsize(*head_a);
	size_b = ft_lstsize(*head_b);
	while (first)
	{
		first->price = price(first, size_b);
		if (first->target->top_half == first->top_half)
			first->price += diff(first->price, price(first->target, size_a));
		else
			first->price += price(first->target, size_a);
		first = first->next;
	}
}

void	init_nodes(t_list **head_a, t_list **head_b)
{
	set_index(head_a);
	set_index(head_b);
	set_targets(head_a, head_b);
	set_prices(head_a, head_b);
}
