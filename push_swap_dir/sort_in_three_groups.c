/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_three_groups.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:37:31 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:37:33 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stk	*find_max_depth_not_sorted_elem(t_stk *a, t_stk *b)
{
	t_stk	*max_elem;
	int		max_depth;

	max_elem = a;
	max_depth = 0;
	while (a)
	{
		if (!a->is_sort && max_depth < a->depth)
		{
			max_elem = a;
			max_depth = a->depth;
		}
		a = a->next;
	}
	while (b)
	{
		if (!b->is_sort && max_depth < b->depth)
		{
			max_elem = b;
			max_depth = b->depth;
		}
		b = b->next;
	}
	return (max_elem->is_sort ? NULL : max_elem);
}

void	sorting_group_a(t_stk **a, t_stk **b, t_stk *sort_elem, t_groups *grp)
{
	_Bool on_top;

	on_top = (sort_elem == *a) ? 1 : 0;
	sort_elem = (on_top) ? sort_elem : find_last_elem(sort_elem);
	while ((on_top && *a && (*a)->depth == grp->depth) ||
			(!on_top && sort_elem->depth == grp->depth))
	{
		if (!on_top)
			reverse_rotate(a);
		if (on_top && sort_elem->index > grp->two_thirds)
			rotate(a);
		else if (sort_elem->index <= grp->two_thirds)
		{
			push(b, a);
			if (sort_elem->index <= grp->third)
				rotate(b);
		}
		if (sort_elem->index > grp->two_thirds)
			sort_elem->depth = sort_elem->depth * 10 + 3;
		else if (sort_elem->index <= grp->third)
			sort_elem->depth = sort_elem->depth * 10 + 1;
		else
			sort_elem->depth = sort_elem->depth * 10 + 2;
		sort_elem = (on_top) ? *a : find_last_elem(*a);
	}
}

void	sorting_group_b(t_stk **a, t_stk **b, t_stk *sort_elem, t_groups *grp)
{
	_Bool on_top;

	on_top = (sort_elem == *b) ? 1 : 0;
	sort_elem = (on_top) ? sort_elem : find_last_elem(sort_elem);
	while ((on_top && *b && (*b)->depth == grp->depth) ||
			(!on_top && sort_elem->depth == grp->depth))
	{
		if (!on_top)
			reverse_rotate(b);
		if (on_top && sort_elem->index <= grp->third)
			rotate(b);
		else if (sort_elem->index > grp->third)
		{
			push(a, b);
			if (sort_elem->index <= grp->two_thirds)
				rotate(a);
		}
		if (sort_elem->index <= grp->third)
			sort_elem->depth = sort_elem->depth * 10 + 1;
		else if (sort_elem->index > grp->two_thirds)
			sort_elem->depth = sort_elem->depth * 10 + 3;
		else
			sort_elem->depth = sort_elem->depth * 10 + 2;
		sort_elem = (on_top) ? *b : find_last_elem(*b);
	}
}

void	sort_in_two_groups(t_stk **a, t_stk **b, t_stk *sort_elem,t_groups *grp)
{
	if (sort_elem->stack_name == 'a')
	{
		grp->two_thirds = (grp->third + grp->two_thirds) / 2;
		grp->third = -1;
		sorting_group_a(a, b, sort_elem, grp);
	}
	else
	{
		grp->third = (grp->third + grp->two_thirds) / 2;
		grp->two_thirds = -1;
		sorting_group_b(a, b, sort_elem, grp);
	}
}

void	sort_in_three_groups(t_stk **a, t_stk **b)
{
	t_groups	grp;
	t_stk		*sort_group;
	int			len;

	sort_group = find_max_depth_not_sorted_elem(*a, *b);
	find_thirds(sort_group, &grp.third, &grp.two_thirds);
	grp.depth = sort_group->depth;
	if ((len = lst_group_len(*a)) > 3 && len <= 6)
		sort_in_two_groups(a, b, sort_group, &grp);
	else if (sort_group->stack_name == 'a')
		sorting_group_a(a, b, sort_group, &grp);
	else
		sorting_group_b(a, b, sort_group, &grp);
}
