//
// Created by Mort Deanne on 13/12/2019.
//

#include "push_swap.h"

void min_mid_max_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
	rotate(a);
	swap(b);
	push(a, b);
	push(a, b);
	reverse_rotate(a);
}

void max_min_mid_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
    swap(b);
    push(a, b);
    push(a, b);
}

void min_max_mid_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
    rotate(a);
	push(a, b);
	push(a, b);
	reverse_rotate(a);
}

void mid_max_min_b_top(t_stk **a, t_stk **b)
{
	swap(b);
	push(a, b);
	push(a, b);
	push(a, b);
}

void mid_min_max_b_top(t_stk **a, t_stk **b)
{
	push(a, b);
	rotate(a);
	swap(b);
	push(a, b);
	reverse_rotate(a);
	push(a, b);
}