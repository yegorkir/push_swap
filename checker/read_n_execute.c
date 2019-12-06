//
// Created by Mort Deanne on 03/12/2019.
//

#include "../checker/stack.h"
#include "../checker/checker.h"

int read_n_execute(char *input, t_stack **a, t_stack **b)
{

	while (get_next_line(0, &input) > 0)
	{
		if (!*input)
			break;
		perform_rule(input, a, b);
	}
	return (0);
}