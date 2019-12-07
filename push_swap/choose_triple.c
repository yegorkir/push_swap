//
// Created by Mort Deanne on 07/12/2019.
//

#include "../checker/stack.h"
#include "push_swap.h"

int 	choose_triple_algorith(t_stack **stack)
{
	int min;
	int max;
	int len;

	max = find_min_max(*stack, &min);
	len = lst_group_len(*stack);
	if (min == max ||
		((*stack)->stack_name == 'a' && check_ascending(*stack, len)) ||
		((*stack)->stack_name == 'b' && check_descending(*stack, len)))
		return (1);
	else if (ABS(min - max) == 1)
		swap(stack);
	else if (min == (*stack)->index)
	{
		if (max == (*stack)->next->index)
			min_max_mid(stack);
		else
			max_mid_min(stack);
	}
}