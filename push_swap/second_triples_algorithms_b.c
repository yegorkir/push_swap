//
// Created by Mort Deanne on 13/12/2019.
//

#include "push_swap.h"

void min_mid_max_second(t_stack **a, t_stack **b)
{
	push(a, b);
	rotate(a);
	swap(b);
	push(a, b);
	push(a, b);
	reverse_rotate(a);
}

void max_min_mid_second(t_stack **a, t_stack **b)
{
	push(a, b);
    swap(b);
    push(a, b);
    push(a, b);
}

void min_max_mid_second(t_stack **a, t_stack **b)
{
	push(a, b);
    rotate(a);
	push(a, b);
	push(a, b);
	reverse_rotate(a);
}

void mid_max_min_second(t_stack **a, t_stack **b)
{
	swap(b);
	push(a, b);
	push(a, b);
	push(a, b);
}

void mid_min_max_second(t_stack **a, t_stack **b)
{
	push(a, b);
	rotate(a);
	swap(b);
	push(a, b);
	reverse_rotate(a);
	push(a, b);
}