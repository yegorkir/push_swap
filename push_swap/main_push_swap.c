//
// Created by Mort Deanne on 03/12/2019.
//

#include <stdio.h>

#include "ft_stack.h"
#include "../checker/checker.h"

#include "push_swap.h"

void print_list(t_stk *stack)
{
	printf("-----------------\n");
	while (stack)
	{
		printf("%d\t%d\n", stack->number, stack->index);
		stack = stack->next;
	}
	printf("-----------------\n");
}

int main(int ac, char **av)
{
	t_stk	*a = NULL;
	t_stk *b = NULL;
	char *line;

	a = NULL;
	while (ac > 1)
		push_front(&a, create(av[--ac]));

	indexing_list(a);

	sorter(&a, &b);

	clear_list(&a);
	clear_list(&b);
	return 0;
}


/*#include <stdio.h>
int main()
{
	printf("%.g\n", 0.000000000000006);
	printf("%.g\n", 99.99);
	printf("%.g\n", 5000.);
	printf("%.g\n", 0.00034);
	printf("%.g\n", 0.99);
	printf("%.g\n", 0.09);

	return 0;
}*/

/*
#include <stdio.h>
int main()
{
	int third;
	int two_thirds;
	find_thirds(10, 20, &third, &two_thirds);
	printf("%d %d", third, two_thirds);
	return 0;
}*/
