/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:37:22 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 04:08:31 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort(a, b);
	free_all(a, b, splitted, av);
}
