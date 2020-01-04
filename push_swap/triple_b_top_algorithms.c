/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_b_top_algorithms.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:33:57 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 19:33:59 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_mid_max_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
	rotate(a);
	swap(b);
	push(a, b);
	push(a, b);
	reverse_rotate(a);
	set_group_as_sorted(*a);
}

void	max_min_mid_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
	swap(b);
	push(a, b);
	push(a, b);
	set_group_as_sorted(*a);
}

void	min_max_mid_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
	rotate(a);
	push(a, b);
	push(a, b);
	reverse_rotate(a);
	set_group_as_sorted(*a);
}

void	mid_max_min_b_top(t_stk **a, t_stk **b)
{
	swap(b);
	push(a, b);
	push(a, b);
	push(a, b);
	set_group_as_sorted(*a);
}

void	mid_min_max_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
	rotate(a);
	swap(b);
	push(a, b);
	reverse_rotate(a);
	push(a, b);
	set_group_as_sorted(*a);
}
