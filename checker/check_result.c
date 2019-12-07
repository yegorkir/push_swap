//
// Created by Mort Deanne on 09/10/2019.
//

#include "stack.h"

_Bool check_ascending(t_stack *stack, int n)
{
	int prev;
	int i;

	if (!stack)
		return (1);
	prev = stack->number;
	stack = stack->next;
	i = 0;
	while (stack && (!n || i < n))
	{
		if (stack->number < prev)
			return (0);
		prev = stack->number;
		stack = stack->next;
	}
	return (1);
}

_Bool check_descending(t_stack *stack, int n)
{
	int prev;
	int i;

	if (!stack)
		return (1);
	prev = stack->number;
	stack = stack->next;
	i = 0;
	while (stack && (!n || i < n))
	{
		if (stack->number > prev)
			return (0);
		prev = stack->number;
		stack = stack->next;
	}
	return (1);
}

void check_result(t_stack *a, t_stack *b)
{
	if (b || !check_ascending(a, 0))
	{
		clear_list(&a);
		clear_list(&b);
		go_exit(1);
	}
}