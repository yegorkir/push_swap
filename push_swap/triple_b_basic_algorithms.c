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

void	reverse_rotate_group(t_stk **dst, t_stk **src, t_stk *last_group_src)
{
	while (last_group_src->stack_name == (*src)->stack_name)
	{

	}
}