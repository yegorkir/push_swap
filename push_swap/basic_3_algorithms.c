//
// Created by Mort Deanne on 06/12/2019.
//

#include "../checker/stack.h"

void	mid_min_max(t_stack **stack, char name_stack)
{
	if (name_stack == 'a')
		swap(stack); /// A
	else
	{
		rotate(stack); /// E
		swap(stack);
		reverse_rotate(stack);
		swap(stack);
	}
}

void	mid_max_min(t_stack **stack, char name_stack)
{
	if (name_stack == 'a')
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

void	min_max_mid(t_stack **stack, char name_stack)
{
	if (name_stack == 'a')
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

void	max_min_mid(t_stack **stack, char name_stack)
{
	if (name_stack == 'a')
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

void	max_mid_min(t_stack **stack, char name_stack)
{
	if (name_stack == 'a')
	{
		swap(stack);
		rotate(stack);
		swap(stack);
		reverse_rotate(stack);
		swap(stack);
	}
}