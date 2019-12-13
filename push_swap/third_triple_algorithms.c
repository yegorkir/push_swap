//
// Created by Mort Deanne on 06/12/2019.
//


#include "push_swap.h"

void mid_min_max_a(t_stack **stack)
{
	swap(stack); /// A
}

void mid_max_min_a(t_stack **stack)
{
	rotate(stack); /// E
	swap(stack);
	reverse_rotate(stack);
	swap(stack);
}

void min_max_mid_a(t_stack **stack)
{
	rotate(stack); /// B
	swap(stack);
	reverse_rotate(stack);
}

void max_min_mid_a(t_stack **stack)
{
		swap(stack); /// C
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
}

void max_mid_min_a(t_stack **stack)
{
		swap(stack); //D
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
		swap(stack);
}