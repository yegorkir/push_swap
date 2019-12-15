//
// Created by Mort Deanne on 06/12/2019.
//


#include "push_swap.h"

void mid_min_max_a_top(t_stk **stack)
{
	swap(stack); /// A
}

void mid_max_min_a_top(t_stk **stack)
{
	rotate(stack); /// E
	swap(stack);
	reverse_rotate(stack);
	swap(stack);
}

void min_max_mid_a_top(t_stk **stack)
{
	rotate(stack); /// B
	swap(stack);
	reverse_rotate(stack);
}

void max_min_mid_a_top(t_stk **stack)
{
		swap(stack); /// C
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
}

void max_mid_min_a_top(t_stk **stack)
{
		swap(stack); //D
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
		swap(stack);
}