//
// Created by Mort Deanne on 07/12/2019.
//

#include "../checker/stack.h"
#include "push_swap.h"

void 	third_triple_algorithm(t_stack **stack, t_part *part)
{
	if (part->len == 2 && check_descending(*stack, part->len)) /// max->min
		swap(stack);
	else if (check_descending(*stack, part->len))
		max_mid_min_a(stack);
	else if (part->min == (*stack)->index)
		min_max_mid_a(stack);
	else if (part->max == (*stack)->index)
		max_min_mid_a(stack);
	else if (part->min == (*stack)->next->index)
		mid_min_max_a(stack);
	else if (part->max == (*stack)->next->index)
		mid_max_min_a(stack);
}

void 	second_triple_algorithm(t_stack **a, t_stack **b, t_part *part)
{
	if (part->len == 2) /// min->max
	{
		if (check_ascending(*a, part->len))
			swap(b);
		push(a, b);
		push(a, b);
	}
	else if (check_ascending(*a, part->len))
		MIN_MID_MAX_B(a);
	else if (part->max == (*a)->index)
		MAX_MIN_MID_B(a);
	else if (part->min == (*a)->index)
		MIN_MAX_MID_B(a);
	else if (part->max == (*a)->next->index)
		MID_MAX_MIN_B(a);
	else if (part->min == (*a)->next->index)
		MID_MIN_MAX_B(a);
}

int 	choose_triple_algorithm(t_stack **stack)
{
	t_part part;

	part.max = find_min_max(*stack, &part.min);
	part.len = lst_group_len(*stack);
	if (part.min == part.max ||
	((*stack)->stack_name == 'a' && check_ascending(*stack, part.len)) ||
	((*stack)->stack_name == 'b' && check_descending(*stack, part.len)))
		return (1);
	else if ((*stack)->stack_name == 'a')
		third_triple_algorithm(stack, &part);
	else
		second_triple_algorithm(stack, &part);
	return (1);
}

