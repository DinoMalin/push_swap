/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcario <jcario@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:48:43 by jcario            #+#    #+#             */
/*   Updated: 2023/11/27 04:08:20 by jcario           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

# define MAX_INT 2147483647
# define MIN_INT -2147483648

void	push(t_list	**head_a, t_list **head_b, int push_a);
void	swap(t_list **head, char stack_name, int print);
void	rotate(t_list	**head, char stack_name, int print);
void	reverse_rotate(t_list **head, char stack_name, int print);

int		is_sorted(t_list **head);
t_list	*get_max(t_list **head);
void	sort(t_list **head_a, t_list **head_b);

void	init_nodes(t_list **head_a, t_list **head_b);
void	move_nodes(t_list **head_a, t_list **head_b);

void	print_stack(t_list	*stack, char name);

int		price(t_list *node, int size);
int		diff(int a, int b);
int		size_double_dimensions_array(char **arr);
void	free_all(t_list **head_a, t_list **head_b, int splitted, char **av);

void	ss(t_list **head_a, t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);

void	error(t_list **head_a, t_list **head_b, int splitted, char **av);
int		get_stack(int ac, char **av, t_list **start);
int		check_digit(int ac, char **av);
int		check_doubles(t_list **head);

#endif