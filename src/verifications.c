/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:52:59 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 14:24:51 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_list **head_a, t_list **head_b, int splitted, char **av)
{
	free_all(head_a, head_b, splitted, av);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	check_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	get_stack(int ac, char **av, t_list **start)
{
	int		i;
	t_list	*new_node;

	i = -1;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) > MAX_INT || ft_atoi(av[i]) < MIN_INT)
			return (0);
		new_node = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(start, new_node);
	}
	return (1);
}

int	check_doubles(t_list **head)
{
	t_list	*first;
	t_list	*second;

	first = *head;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (second->content == first->content)
				return (0);
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}
