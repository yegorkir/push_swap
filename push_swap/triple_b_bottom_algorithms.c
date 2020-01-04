/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_b_bottom_algorithms.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:33:51 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 19:33:53 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_mid_max_b_bottom(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	push(a, b);
	reverse_rotate(b);
	reverse_rotate(b);
	swap(b);
	push(a, b);
	push(a, b);
	set_group_as_sorted(*a);
}

void	max_min_mid_b_bottom(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	swap(b);
	push(a, b);
	push(a, b);
	set_group_as_sorted(*a);
}

void	min_max_mid_b_bottom(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	push(a, b);
	reverse_rotate(b);
	push(a, b);
	set_group_as_sorted(*a);
}

void	mid_max_min_b_bottom(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	reverse_rotate(b);
	push(a, b);
	push(a, b);
	set_group_as_sorted(*a);
}

void	mid_min_max_b_bottom(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	push(a, b);
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	push(a, b);
	set_group_as_sorted(*a);
}
