//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "../push_swap/push_swap.h"

#include <stdio.h>

void	sort_in_three_groups(t_stk **from, t_stk **to, char name_from)
{
	int	third;
	int	two_thirds;
	int depth;

	find_thirds(*from, &third, &two_thirds);
	depth = (*from)->depth;
	while (from && (*from)->depth == depth)
	{
		if ((*from)->index <= third)
		{
			(*from)->depth = 10 * (*from)->depth + 1;
			push(to, from);
			rotate(to);
		}
		else if ((*from)->index > two_thirds)
		{
			(*from)->depth = 10 * (*from)->depth + 2;
			push(to, from);
		}
		else
		{
			(*from)->depth = 10 * (*from)->depth + 3;
			rotate(from);
		}
	}
}

/*void	push_rotate_first_third(t_stk **to, t_stk **from, char name_from)
{
	(*from)->depth = 10 * (*from)->depth + 1;
	push(to, from);
	rotate(to);
}

void	push_second_third(t_stk **to, t_stk **from, char name_from)
{
	(*from)->depth = 10 * (*from)->depth + 2;
	push(to, from);
}

void	rotate_third_third(t_stk **from, char name_from)
{
	(*from)->depth = 10 * (*from)->depth + 3;
	rotate(from);
}*/

/*void	sort_in_three_groups(t_stk **from, t_stk **to, char name_from)
	{
	int	third;
	int	two_thirds;
	int depth;

	find_thirds(*from, &third, &two_thirds);
	depth = (*from)->depth;
	while (from && (*from)->depth == depth)
	{
		if ((*from)->index <= third)
			push_rotate_first_third(to, from, name_from);
		else if ((*from)->index > two_thirds)
			rotate_third_third(from, name_from);
		else
			push_second_third(to, from, name_from);
	}
}*/

void 	choose_stack_sort_in_three_groups(t_stk **first, t_stk **second, char name_from)
{
	if (name_from == 'a')
		sort_in_three_groups(first, second, name_from);
	else
		sort_in_three_groups(second, first, name_from);
}