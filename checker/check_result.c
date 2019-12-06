//
// Created by Mort Deanne on 09/10/2019.
//

#include "stack.h"

_Bool check_ascending(t_stack *a)
{
	int prev;

	if (!a)
		return (1);
	prev = a->number;
	a = a->next;
	while (a)
	{
		if (a->number < prev)
			return (0);
		prev = a->number;
		a = a->next;
	}
	return (1);
}

void check_result(t_stack *a, t_stack *b)
{
	if (b || !check_ascending(a))
	{
		clear_list(&a);
		clear_list(&b);
		go_exit(1);
	}
}