/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:37:06 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 03:05:40 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	diff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int	price(t_list *node, int size)
{
	if (node->top_half)
		return (node->index);
	else
		return (size - node->index);
}

int	size_double_dimensions_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_all(t_list **head_a, t_list **head_b, int splitted, char **av)
{
	int		i;
	t_list	*first;
	t_list	*to_free;

	i = 0;
	first = *head_a;
	while (first)
	{
		to_free = first;
		first = first->next;
		free(to_free);
	}
	free(head_a);
	free(head_b);
	if (splitted)
	{
		while (av[i])
			free(av[i++]);
		free(av);
	}
}
