//
// Created by Mort Deanne on 06/12/2019.
//

#include "../checker/stack.h"

int		find_min_max(t_stack *stack, int *min)
{
	int depth;
	int max;

	depth = stack->depth;
	*min = stack->index;
	max = stack->index;
	while(stack && stack->depth == depth)
	{
		if (*min > stack->index)
			*min = stack->index;
		else if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}

	return (max);
}

int		find_thirds(int min, int max, int *third, int *two_thirds)
{
	int modulo;

	max -= min - 1;
	modulo = max % 3;
	*third = max / 3;
	*two_thirds = *third * 2;
	if (modulo)
	{
		(*third)++;
		(*two_thirds)++;
	}
	if (modulo == 2)
		(*two_thirds)++;
	*third += min - 1;
	*two_thirds += min - 1;
	return (0);
}