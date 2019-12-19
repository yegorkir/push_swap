//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "push_swap.h"

_Bool	is_group_triple(t_stk *a, t_stk *b)
{
	if (lst_group_len(a) <= 3 &&
		lst_group_len(find_last_group(a)) <= 3 &&
		lst_group_len(find_last_group(b)) <= 3)
		return (1);
	return (0);
}

void print_list(t_stk *stack);

void	sorter(t_stk **a, t_stk **b)
{
	int i;

	i = 0;
	while (b|| i == 0)
	{
		i++;
		if (i == 9)
		{
			print_list(*a);
			print_list(*b);
		}
		while (!is_group_triple(*a, *b))
			sort_in_three_groups(a , b);
		sort_triples(a, b);
	}

}