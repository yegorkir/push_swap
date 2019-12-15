//
// Created by Mort Deanne on 09/10/2019.
//

#include "ft_stack.h"

_Bool check_ascending(t_stk *stack, int n)
{
	int prev;
	int i;

	if (!stack)
		return (1);
	prev = stack->number;
	stack = stack->next;
	i = 1;
	while (stack && (!n || i < n))
	{
		if (stack->number < prev)
			return (0);
		prev = stack->number;
		stack = stack->next;
		i++;
	}
	return (1);
}

_Bool check_descending(t_stk *stack, int n)
{
	int prev;
	int i;

	if (!stack)
		return (1);
	prev = stack->number;
	stack = stack->next;
	i = 1;
	while (stack && (!n || i < n))
	{
		if (stack->number > prev)
			return (0);
		prev = stack->number;
		stack = stack->next;
		i++;
	}
	return (1);
}

void check_result(t_stk *a, t_stk *b)
{
	if (b || !check_ascending(a, 0))
	{
		clear_list(&a);
		clear_list(&b);
		go_exit(1);
	}
}