//
// Created by Mort Deanne on 15/12/2019.
//

#include "push_swap.h"


void max_min_mid_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	rotate(a);
	swap(a);
	reverse_rotate(a);
}

void min_max_mid_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	reverse_rotate(a);
}

void mid_max_min_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	reverse_rotate(a);
	swap(a);
}

void mid_min_max_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
}

void max_mid_min_a_bottom(t_stk **a)
{
	reverse_rotate(a);
	reverse_rotate(a);
	reverse_rotate(a);
	swap(a);
	rotate(a);
	swap(a);
	reverse_rotate(a);
}