/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:19:50 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 03:42:50 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_cheapest_node(t_list **head_b)
{
	t_list	*first;
	t_list	*result;

	first = *head_b;
	result = first;
	while (first)
	{
		if (first->price < result->price)
			result = first;
		first = first->next;
	}
	return (result);
}

void	put_to_top(t_list **head, t_list *node, char name)
{
	while (*head != node)
	{
		if (node->top_half)
			rotate(head, name, TRUE);
		else
			reverse_rotate(head, name, TRUE);
	}
}

void	maxi_rotate(t_list **head_a, t_list **head_b, t_list *cheapest_nd)
{
	if (cheapest_nd->top_half == cheapest_nd->target->top_half)
	{
		while (*head_a != cheapest_nd->target && *head_b != cheapest_nd)
		{
			if (cheapest_nd->top_half && cheapest_nd->target->top_half)
			{
				rotate(head_a, 'a', FALSE);
				rotate(head_b, 'b', FALSE);
				ft_printf("rr\n");
			}
			else if (!cheapest_nd->top_half && !cheapest_nd->target->top_half)
			{
				reverse_rotate(head_a, 'a', FALSE);
				reverse_rotate(head_b, 'b', FALSE);
				ft_printf("rrr\n");
			}
		}
	}
	put_to_top(head_a, cheapest_nd->target, 'a');
	put_to_top(head_b, cheapest_nd, 'b');
}

void	move_nodes(t_list **head_a, t_list **head_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest_node(head_b);
	maxi_rotate(head_a, head_b, cheapest_node);
	push(head_a, head_b, TRUE);
}
