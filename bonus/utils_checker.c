/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:36:35 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 14:22:50 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **head_a, t_list **head_b)
{
	swap(head_a, 'a', FALSE);
	swap(head_b, 'b', FALSE);
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a, 'a', FALSE);
	rotate(head_b, 'b', FALSE);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	reverse_rotate(head_a, 'a', FALSE);
	reverse_rotate(head_b, 'b', FALSE);
}
