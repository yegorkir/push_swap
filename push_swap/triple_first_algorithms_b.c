//
// Created by Mort Deanne on 15/12/2019.
//

#include "push_swap.h"

void min_mid_max_first(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	push(a, b);
	reverse_rotate(b);
	reverse_rotate(b);
	swap(b);
	push(a, b);
	push(a, b);
}

void max_min_mid_first(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	swap(b);
	push(a, b);
	push(a, b);
}

void min_max_mid_first(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	push(a, b);
	reverse_rotate(b);
	push(a, b);
}

void mid_max_min_first(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	reverse_rotate(b);
	push(a, b);
	push(a, b);
}

void mid_min_max_first(t_stk **a, t_stk **b)
{
	reverse_rotate(b);
	push(a, b);
	reverse_rotate(b);
	reverse_rotate(b);
	push(a, b);
	push(a, b);
}