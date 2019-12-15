//
// Created by Mort Deanne on 07/12/2019.
//

#include "ft_stack.h"
#include "push_swap.h"

void	sorter(t_stk **first, t_stk **second)
{
	while (lst_group_len(*first) > 3)
		sort_in_three_groups_a(first, second);

}