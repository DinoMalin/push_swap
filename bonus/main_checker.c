/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:13:22 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 15:13:30 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process(char *instruction, t_list **head_a, t_list **head_b)
{
	if (!ft_strncmp(instruction, "pa", 2))
		push(head_a, head_b, 2);
	else if (!ft_strncmp(instruction, "pb", 2))
		push(head_b, head_a, 2);
	else if (!ft_strncmp(instruction, "sa", 2))
		swap(head_a, 'a', FALSE);
	else if (!ft_strncmp(instruction, "sb", 2))
		swap(head_b, 'b', FALSE);
	else if (!ft_strncmp(instruction, "ss", 2))
		ss(head_a, head_b);
	else if (!ft_strncmp(instruction, "ra", 2))
		rotate(head_a, 'a', FALSE);
	else if (!ft_strncmp(instruction, "rb", 2))
		rotate(head_b, 'b', FALSE);
	else if (!ft_strncmp(instruction, "rr", 3))
		rr(head_a, head_b);
	else if (!ft_strncmp(instruction, "rra", 3))
		reverse_rotate(head_a, 'a', FALSE);
	else if (!ft_strncmp(instruction, "rrb", 3))
		reverse_rotate(head_b, 'b', FALSE);
	else if (!ft_strncmp(instruction, "rrr", 3))
		rrr(head_a, head_b);
	else
		return (0);
	return (1);
}

void	loop(t_list **head_a, t_list **head_b, int splitted, char **av)
{
	char	*next_line;
	int		success;

	next_line = get_next_line(0);
	if (!next_line)
	{
		if (is_sorted(head_a) && !*head_b)
			ft_printf("OK\n");
		free(next_line);
		return ;
	}
	while (next_line)
	{
		success = process(next_line, head_a, head_b);
		free(next_line);
		if (!success)
			error(head_a, head_b, splitted, av);
		next_line = get_next_line(0);
	}
	if (is_sorted(head_a) && !*head_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	int		splitted;

	if (ac <= 1 || (ac == 2 && !av[1][0]))
		return (0);
	av++;
	splitted = FALSE;
	if (ac == 2)
	{
		av = ft_split(av[0], ' ');
		ac = size_double_dimensions_array(av);
		splitted = TRUE;
	}
	else
		ac--;
	b = malloc(sizeof(t_list *));
	*b = NULL;
	a = malloc(sizeof(t_list *));
	*a = NULL;
	if (!get_stack(ac, av, a) || !check_doubles(a) || !check_digit(ac, av))
		error(a, b, splitted, av);
	loop(a, b, splitted, av);
	free_all(a, b, splitted, av);
}
