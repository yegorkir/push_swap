//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "../push_swap/push_swap.h"

#include <stdio.h>

void	sort_in_three_groups_a(t_stk **a, t_stk **b)
{
	int	third;
	int	two_thirds;
	int depth;

	find_thirds(*a, &third, &two_thirds);
	depth = (*a)->depth;
	while (a && (*a)->depth == depth)
	{
		if ((*a)->index <= third)
		{
			(*a)->depth = 10 * (*a)->depth + 1;
			push(b, a);
			rotate(b);
		}
		else if ((*a)->index > two_thirds)
		{
			(*a)->depth = 10 * (*a)->depth + 3;
			rotate(a);
		}
		else
		{
			(*a)->depth = 10 * (*a)->depth + 2;
			push(b, a);
		}
	}
}

void	sort_in_three_groups_b(t_stk **a, t_stk **b)
{
	int	third;
	int	two_thirds;
	int depth;

	find_thirds(*b, &third, &two_thirds);
	depth = (*b)->depth;
	while (b && (*b)->depth == depth)
	{
		if ((*b)->index <= third)
		{
			(*b)->depth = 10 * (*b)->depth + 1;
			push(a, b);
			rotate(a);
		}
		else if ((*b)->index > two_thirds)
		{
			(*b)->depth = 10 * (*b)->depth + 3;
			push(a, b);
		}
		else
		{
			(*b)->depth = 10 * (*b)->depth + 2;
			rotate(b);
		}
	}
}