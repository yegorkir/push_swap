//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "../push_swap/push_swap.h"

#include <stdio.h>



t_stk	*find_last_elem(t_stk *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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



void sorting_group_a(t_stk **a, t_stk **b, t_stk *sort_elem, t_groups *grp)
{
	_Bool on_top;

	on_top = (sort_elem == *a) ? 1 : 0;
	sort_elem = (on_top) ? sort_elem : find_last_elem(sort_elem);
	while ((on_top && *a && (*a)->depth == grp->depth) ||
		   (!on_top && sort_elem->depth == grp->depth))
	{
		if (sort_elem->index > grp->two_thirds)
		{
			sort_elem->depth = sort_elem->depth * 10 + 3;
			on_top ? rotate(a) : reverse_rotate(a);
		}
		else
		{
			push(b, a);
			if (sort_elem->index <= grp->third)
			{
				sort_elem->depth = sort_elem->depth * 10 + 1;
				rotate(b);
			}
			else
				sort_elem->depth = sort_elem->depth * 10 + 2;
		}
		sort_elem = (on_top) ? *a : find_last_elem(*a);
	}
}

void sorting_group_b(t_stk **a, t_stk **b, t_stk *sort_elem, t_groups *grp)
{
	_Bool on_top;

	on_top = (sort_elem == *b) ? 1 : 0;
	if (!on_top)
		sort_elem = find_last_elem(sort_elem);
	while ((on_top && *b && (*b)->depth == grp->depth) ||
		   (!on_top && sort_elem->depth == grp->depth))
	{
		if (sort_elem->index <= grp->third)
			(on_top) ? rotate(b) : reverse_rotate(b);
		else
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

void	sort_in_three_groups(t_stk **a, t_stk **b)
{
	t_groups	grp;
	t_stk		*sort_group;

	sort_group = find_max_depth_not_sorted_elem(*a, *b);
	find_thirds(sort_group, &grp.third, &grp.two_thirds);
	grp.depth = sort_group->depth;
	if (sort_group->stack_name == 'a')
		sorting_group_a(a, b, sort_group, &grp);
	else
		sorting_group_b(a, b, sort_group, &grp);
}
