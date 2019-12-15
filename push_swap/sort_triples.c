//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "push_swap.h"

t_stk	*find_last_group_b(t_stk *b)
{
	t_stk *head_group;

	head_group = b;
	while (b)
	{
		if (head_group->depth != b->depth)
			head_group = b;
		b = b->next;
	}
	return (head_group);
}

void 	third_triple_algorithm(t_stk **a, t_part *part)
{
	if (part->len == 2 && check_descending(*a, part->len)) /// max->min
		swap(a);
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

void 	second_triple_algorithm(t_stk **a, t_stk **b, t_part *part)
{
	if (part->max - part->min == 1) /// min->max
	{
		swap(b);
		push_group(a, b);
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

void 	first_triple_algorithm(t_stk **a, t_stk **b, t_stk *last_group_b, t_part *part)
{
	if (check_descending(last_group_b, part->len))
	{
		reverse_rotate_group(b, last_group_b);
		push_group(a, b);
	}
	else if (part->max - part->min == 1) /// min->max
	{
		reverse_rotate_group(b, last_group_b);
		swap(b);
		push_group(a, b);
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

void sort_triples(t_stk **a, t_stk **b)
{
	t_part part;
	t_stk *last_group_b;

	part.max = find_min_max(*a, &part.min);
	part.len = lst_group_len(*a);
	if (part.len != 1 && !check_ascending(*a, part.len))
		third_triple_algorithm(a, &part);
	part.max = find_min_max(*b, &part.min);
	part.len = lst_group_len(*b);
	if (part.len != 1 && !check_descending(*b, part.len))
		second_triple_algorithm(a, b, &part);
	else
		push_group(a, b);

	last_group_b = find_last_group_b(*b);
	part.max = find_min_max(last_group_b, &part.min);
	part.len = lst_group_len(last_group_b);
	if (part.len != 1 && !check_descending(last_group_b, part.len))
		first_triple_algorithm(a, b, last_group_b, &part);
	else
	{
		reverse_rotate_group(b, last_group_b);
		push_group(a, b);
	}
}

