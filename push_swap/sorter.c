//
// Created by Mort Deanne on 07/12/2019.
//

#include "../checker/stack.h"
#include "push_swap.h"

void	sorter(t_stack **first, t_stack **second)
{
	while (lst_group_len(*first) > 3)
		sort_in_three_groups(first, second, 'a');

}