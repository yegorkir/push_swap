//
// Created by Mort Deanne on 06/12/2019.
//

#include <stack.h>
#include "../push_swap/push_swap.h"

void 	indexing_list(t_stack *stack)
{
	int min;
	int max;
	t_stack *tmp;
	int i;

	max = find_min_max(stack, &min);
	tmp = stack;
	while (tmp)
	{
		tmp->index = tmp->number - min;
		tmp = tmp->next;
	}
	while (max)
	{
		tmp = stack;
		while (1)
		{

		}
	}
}

int		find_elem_by_inx(t_stack *stack, int indx)
{
	while (stack)
	{
		if (stack->index == indx)
	}
}