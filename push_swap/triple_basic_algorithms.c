//
// Created by Mort Deanne on 15/12/2019.
//

#include "push_swap.h"

void	push_group(t_stk **dst, t_stk **src)
{
	int depth;

	depth = (*src)->depth;
	while (*src && depth == (*src)->depth)
		push(dst, src);
}

void	reverse_rotate_group(t_stk **stack, t_stk *last_group_stack)
{
	while (last_group_stack != *stack)
		reverse_rotate(stack);
}

void	set_group_as_sorted(t_stk *a)
{
	int depth;

	depth = a->depth;
	while (a && depth == (a)->depth)
	{
		a->is_sort = 1;
		a = a->next;
	}
}