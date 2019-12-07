//
// Created by Mort Deanne on 06/12/2019.
//

#include "../checker/stack.h"
#include "push_swap.h"

int find_min_max_by_num(t_stack *stack, t_init *init)
{

	while (stack)
	{
		if (!stack->index)
		{
			if (init->min_elem->number > stack->number)
				init->min_elem = stack;
			if (init->max_elem->number < stack->number)
				init->max_elem = stack;
		}
		stack = stack->next;
	}

	if (!init->min_elem->index)
	{
		init->min_elem->index = init->min_indx;
		init->min_indx++;
	}
	if (!init->max_elem->index)
	{
		init->max_elem->index = init->max_indx;
		init->max_indx--;
	}
	return (0);
}

int		lst_group_len(t_stack *stack)
{
	int len;
	int depth;

	depth = stack->depth;
	len = 0;
	while (stack && depth == stack->depth)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int		find_min_max(t_stack *stack, int *min)
{
	int depth;
	int max;

	depth = stack->depth;
	*min = stack->index;
	max = stack->index;
	while (stack && stack->depth == depth)
	{
		if (*min > stack->index)
			*min = stack->index;
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}

	return (max);
}

int find_thirds(t_stack *stack, int *third, int *two_thirds)
{
	int modulo;
	int min;
	int max;

	//////
	if (!stack)
	{
		min = 10;
		max = 21;
	}
	else ////
		max = find_min_max(stack, &min);


	max -= min - 1;
	modulo = max % 3;
	*third = max / 3;
	*two_thirds = *third * 2;
	if (modulo)
		(*two_thirds)++;
	if (modulo == 2)
	{
		(*two_thirds)++;
		(*third)++;
	}
	*third += min - 1;
	*two_thirds += min - 1;
	return (0);
}