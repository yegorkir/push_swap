//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "push_swap.h"

_Bool	is_group_triple(t_stk *a, t_stk *b)
{
	if (lst_group_len(find_max_depth_not_sorted_elem(a, b)) <= 3)
		return (1);
	return (0);
}

void	sorter(t_stk **a, t_stk **b)
{
	int i;

	i = 0;
	while (b|| i == 0)
	{
		i++;
		while (!is_group_triple(*a, *b))
		{
			sort_in_three_groups(a, b);
		}

		if (!*b || !*a)
			return ;
		if (i == 24)
			i = i;
		sort_triples(a, b);
	}

}