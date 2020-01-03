//
// Created by Mort Deanne on 03/12/2019.
//

#include <stdio.h>

#include "ft_stack.h"
#include "../checker/checker.h"

#include "push_swap.h"


int check_next_prev(t_stk *head)
{
	t_stk *next;
	int not_good = 0;
	int i = 0;

	next = head->next;
	while (next && head)
	{
		i++;
		if (next->prev != head)
			not_good++;
		head = head->next;
		next = next->next;
	}
	return (not_good);
}

void print_list(t_stk *stack)
{
	printf("-----------------\n");
	int i = 0;

	while (stack)
	{
		i++;
		printf("%d\t\t%d\t%d\n", stack->is_sort, stack->index, stack->depth);
		stack = stack->next;
	}
	printf("-----------------\n");
}

void print_lists(t_stk *a, t_stk *b)
{
	print_list(a);
	print_list(b);
}

void print_group(t_stk *stack)
{
	int depth;

	depth = stack->depth;
	while (stack && stack->depth == depth)
	{
		printf("%d\t%c\t%d\t%d\n", stack->is_sort, stack->stack_name, stack->index, stack->depth);
		stack = stack->next;
	}
}

int len_sorted(t_stk *a)
{
	int len = 0;

	while (a && a->is_sort == 0)
		a = a->next;
	while (a && a->is_sort == 1)
	{
		len++;
		a = a->next;
	}
}

void print_top_bottom_groups(t_stk *a, t_stk *b)
{
	int depth_a;
	int depth_b;
	int len_srt = len_sorted(a);


	depth_a = a->depth;
	depth_b = b->depth;

	while (a && b)
	{
		if (a->depth == depth_a)
			printf("%d\t%d\t%d", a->is_sort, a->index, a->depth);
		else if (len_srt < 6)
			printf("\x1b[31m%d\t%d\t%d\x1b[37m", a->is_sort, a->index, a->depth);
		else
			printf("\t\t\t");

		if (a->depth > 999 || (a->depth != depth_a && a->is_sort == 0))
			printf("\t");
		else
			printf("\t\t");

		if (b->depth == depth_b)
			printf("%d\t%d\t%d\n", b->is_sort, b->index,b->depth);
		else
			printf("\n");

		a = a->next;
		if (a->depth != depth_a)
			while (a && a->is_sort == 0)
				a = a->next;
		b = b->next;
	}

	//printf("\x1b[31m");
}



int main(int ac, char **av)
{
	t_stk	*a = NULL;
	t_stk	*b = NULL;
	t_stk	*c = NULL;


	a = NULL;
	while (ac > 1)
		push_front(&a, create(av[--ac]));

	indexing_list(a);


	sorter(&a, &b);



	//print_list(a);

	//printf("not good %d\n%p\n", check_next_prev(a), b);
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
