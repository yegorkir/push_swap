/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_a_bottom_algorithms.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:37:56 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:38:05 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	max_min_mid_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	rotate(a);
	swap(a);
	reverse_rotate(a);
	set_group_as_sorted(*a);
}

void	min_max_mid_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	reverse_rotate(a);
	set_group_as_sorted(*a);
}

void	mid_max_min_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	reverse_rotate(a);
	swap(a);
	set_group_as_sorted(*a);
}

void	mid_min_max_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	set_group_as_sorted(*a);
}

void	max_mid_min_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	rotate(a);
	swap(a);
	reverse_rotate(a);
	swap(a);
	set_group_as_sorted(*a);
}
