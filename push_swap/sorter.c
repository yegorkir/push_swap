/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:37:50 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:37:52 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

_Bool	is_group_triple(t_stk *a, t_stk *b)
{
	if (lst_group_len(find_max_depth_not_sorted_elem(a, b)) <= 3)
		return (1);
	return (0);
}

void	sorter(t_stk **a, t_stk **b)
{
	int flag;

	flag = 0;
	while (b || flag == 0)
	{
		flag++;
		while (!is_group_triple(*a, *b))
			sort_in_three_groups(a, b);
		if (!*b || !*a)
			return ;
		sort_triples(a, b);
	}
}
