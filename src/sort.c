/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:06:32 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 03:42:50 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **head)
{
	t_list	*first;

	first = *head;
	while (first && first->next)
	{
		if (first->content > first->next->content)
			return (FALSE);
		first = first->next;
	}
	return (TRUE);
}

t_list	*get_max(t_list **head)
{
	t_list	*max;
	t_list	*first;

	first = *head;
	max = first;
	while (first)
	{
		if (max->content < first->content)
			max = first;
		first = first->next;
	}
	return (max);
}

void	sort_for_size_three(t_list **head)
{
	t_list	*max;

	max = get_max(head);
	if (*head == max)
		rotate(head, 'a', TRUE);
	else if ((*head)->next == max)
		reverse_rotate(head, 'a', TRUE);
	if ((*head)->content > (*head)->next->content)
		swap(head, 'a', TRUE);
}

void	divide_stacks(t_list **head_a, t_list **head_b)
{
	t_list	*max;

	max = get_max(head_a);
	while (ft_lstsize(*head_a) > 3)
	{
		if (*head_a != max)
			push(head_b, head_a, FALSE);
		else
			rotate(head_a, 'a', TRUE);
	}
}

void	sort(t_list **head_a, t_list **head_b)
{
	t_list	*max;

	if (is_sorted(head_a))
		return ;
	divide_stacks(head_a, head_b);
	sort_for_size_three(head_a);
	while (*head_b)
	{
		init_nodes(head_a, head_b);
		move_nodes(head_a, head_b);
	}
	max = get_max(head_a);
	while (ft_lstlast(*head_a) != max)
	{
		if (max->top_half)
			rotate(head_a, 'a', TRUE);
		else
			reverse_rotate(head_a, 'a', TRUE);
	}
}
