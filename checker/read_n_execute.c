//
// Created by Mort Deanne on 03/12/2019.
//

#include "ft_stack.h"
#include "../checker/checker.h"

int read_n_execute(char *input, t_stk **a, t_stk **b)
{

	while (get_next_line(0, &input) > 0)
	{
		if (!*input)
			break;
		perform_rule(input, a, b);
	}
	return (0);
}