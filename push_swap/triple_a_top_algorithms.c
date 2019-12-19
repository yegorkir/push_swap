//
// Created by Mort Deanne on 06/12/2019.
//


#include "push_swap.h"

void mid_min_max_a_top(t_stk **a)
{
	swap(a); /// A
	set_group_as_sorted(*a);
}

void mid_max_min_a_top(t_stk **a)
{
	rotate(a); /// E
	swap(a);
	reverse_rotate(a);
	swap(a);
	set_group_as_sorted(*a);
}

void min_max_mid_a_top(t_stk **a)
{
	rotate(a); /// B
	swap(a);
	reverse_rotate(a);
	set_group_as_sorted(*a);
}

void max_min_mid_a_top(t_stk **a)
{
	swap(a); /// C
	rotate(a);
	swap(a);
	reverse_rotate(a);
	set_group_as_sorted(*a);
}

void max_mid_min_a_top(t_stk **a)
{
	swap(a); //D
	rotate(a);
	swap(a);
	reverse_rotate(a);
	swap(a);
	set_group_as_sorted(*a);
}