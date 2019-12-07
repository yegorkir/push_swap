//
// Created by Mort Deanne on 03/12/2019.
//

#include <stdio.h>

#include "../checker/stack.h"
#include "../checker/checker.h"

#include "push_swap.h"



int main(int ac, char **av)
{
	t_stack	*a = NULL;
	t_stack *b = NULL;
	char *line;

	a = NULL;
	while (ac > 1)
		push_front(&a, create(av[--ac]));

	indexing_list(a);

	b = a;

	printf("9 21 22 5 17 11 23 7 1 19 24 12 13 16 8 26 2 4 14 15 3 25 20 6 18 10\n");
	while (b)
	{
		printf("%d ", b->index);
		b = b->next;
	}
	clear_list(&a);
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
