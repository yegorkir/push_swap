//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "push_swap.h"

t_stk	*find_last_group(t_stk *stack)
{
	t_stk *head_group;

	head_group = stack;
	while (stack)
	{
		if (head_group->depth != stack->depth)
			head_group = stack;
		stack = stack->next;
	}
	return (head_group);
}


void sort_triples(t_stk **a, t_stk **b)
{

	t_stk	*sort_group;
	int 	i;
	t_part	part;

	i = 0;
	while (i++ < 3)
	{
		if (!(sort_group = find_max_depth_not_sorted_elem(*a, *b)))
			return ;
		else if (lst_group_len(sort_group) > 3)
			break ;
		part.max = find_min_max(sort_group, &part.min);
		part.len = lst_group_len(sort_group);
		if (sort_group->stack_name == 'a')
		{
			if (sort_group == *a)
				triple_a_top_algo(a, &part);
			else
				triple_a_bottom_algo(a, sort_group, &part);
		}
		else
		{
			if (sort_group == *b)
				triple_b_top_algo(a, b, &part);
			else
				triple_b_bottom_algo(a, b, sort_group, &part);
		}
	}
}