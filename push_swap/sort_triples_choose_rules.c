//
// Created by Mort Deanne on 19/12/2019.
//

#include <ft_stack.h>
#include "push_swap.h"

void 	triple_a_top_algo(t_stk **a, t_part *part)
{
	if (check_ascending(*a, part->len))
		set_group_as_sorted(*a);
	else if (part->len == 2 && check_descending(*a, part->len)) /// max->min
	{
		swap(a);
		set_group_as_sorted(*a);
	}
	else if (check_descending(*a, part->len))
		max_mid_min_a_top(a);
	else if (part->min == (*a)->index)
		min_max_mid_a_top(a);
	else if (part->max == (*a)->index)
		max_min_mid_a_top(a);
	else if (part->min == (*a)->next->index)
		mid_min_max_a_top(a);
	else if (part->max == (*a)->next->index)
		mid_max_min_a_top(a);
}

void triple_a_bottom_algo(t_stk **a, t_stk *last_group_a, t_part *part)
{
	if (part->len == 1)
	{
		reverse_rotate(a);
		last_group_a->is_sort = 1;
	}
	else if (part->max - part->min == 1) /// min->max
	{
		reverse_rotate_group(a, last_group_a);
		if ((*a)->index - (*a)->next->index == 1)
			swap(a);
		set_group_as_sorted(*a);
	}
	else if (check_descending(last_group_a, part->len))
		max_mid_min_a_bottom(a);
	else if (check_ascending(last_group_a, part->len))
		reverse_rotate_group(a, last_group_a);
	else if (part->max == last_group_a->index)
		max_min_mid_a_bottom(a);
	else if (part->min == last_group_a->index)
		min_max_mid_a_bottom(a);
	else if (part->max == last_group_a->next->index)
		mid_max_min_a_bottom(a);
	else if (part->min == last_group_a->next->index)
		mid_min_max_a_bottom(a);
}

void 	triple_b_top_algo(t_stk **a, t_stk **b, t_part *part)
{
	if (part->len == 1)
	{
		push(a, b);
		(*a)->is_sort = 1;
	}
	if (part->max - part->min == 1) /// min->max
	{
		if ((*a)->index - (*a)->next->index == 1)
			swap(b);
		push_group(a, b);
		set_group_as_sorted(*a);
	}
	else if (part->len > 1 && part->max == (*b)->index && part->min != (*b)->next->index)
	{
		push_group(a, b);
		set_group_as_sorted(*a);
	}
	else if (check_ascending(*b, part->len))
		min_mid_max_b_top(a, b);
	else if (part->max == (*b)->index)
		max_min_mid_b_top(a, b);
	else if (part->min == (*b)->index)
		min_max_mid_b_top(a, b);
	else if (part->max == (*b)->next->index)
		mid_max_min_b_top(a, b);
	else if (part->min == (*b)->next->index)
		mid_min_max_b_top(a, b);
}

void 	triple_b_bottom_algo(t_stk **a, t_stk **b, t_stk *last_group_b,
							 t_part *part)
{
	if (check_descending(last_group_b, part->len))
	{
		reverse_rotate_group(b, last_group_b);
		push_group(a, b);
		set_group_as_sorted(*a);
	}
	else if (part->max - part->min == 1) /// min->max
	{
		reverse_rotate_group(b, last_group_b);
		swap(b);
		push_group(a, b);
		set_group_as_sorted(*a);
	}
	else if (check_ascending(last_group_b, part->len))
		min_mid_max_b_bottom(a, b);
	else if (part->max == last_group_b->index)
		max_min_mid_b_bottom(a, b);
	else if (part->min == last_group_b->index)
		min_max_mid_b_bottom(a, b);
	else if (part->max == last_group_b->next->index)
		mid_max_min_b_bottom(a, b);
	else if (part->min == last_group_b->next->index)
		mid_min_max_b_bottom(a, b);
}