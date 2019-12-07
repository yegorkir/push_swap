//
// Created by Mort Deanne on 06/12/2019.
//


#include "push_swap.h"

void mid_min_max(t_stack **stack)
{
	if ((*stack)->stack_name == 'a')
		swap(stack); /// A
	else
	{
		rotate(stack); /// E
		swap(stack);
		reverse_rotate(stack);
		swap(stack);
	}
}

void mid_max_min(t_stack **stack)
{
	if ((*stack)->stack_name == 'a')
	{
		rotate(stack); /// E
		swap(stack);
		reverse_rotate(stack);
		swap(stack);
	}
	else
	{
		swap(stack); /// A
	}
}

void min_max_mid(t_stack **stack)
{
	if ((*stack)->stack_name == 'a')
	{
		rotate(stack); /// B
		swap(stack);
		reverse_rotate(stack);
	}
	else
	{
		swap(stack); /// C
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
	}
}

void max_min_mid(t_stack **stack)
{
	if ((*stack)->stack_name == 'a')
	{
		swap(stack); /// C
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
	}
	else
	{
		rotate(stack); /// B
		swap(stack);
		reverse_rotate(stack);
	}
}

void max_mid_min(t_stack **stack)
{
		swap(stack);
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
		swap(stack);
}