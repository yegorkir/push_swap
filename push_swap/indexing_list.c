/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:37:07 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:37:09 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static _Bool	need_break(t_init *init)
{
	if (init->min_elem == init->min_last_elem &&
		init->max_elem == init->max_last_elem)
		return (1);
	else
	{
		init->min_last_elem = init->min_elem;
		init->max_last_elem = init->max_elem;
	}
	return (0);
}

static void		find_notindexed_elem(t_stk *stack, t_init *init)
{
	while (stack)
	{
		if (!stack->index)
		{
			init->min_elem = stack;
			init->max_elem = stack;
			break ;
		}
		stack = stack->next;
	}
}

static void		init_init(t_stk *stack, t_init *init)
{
	init->min_elem = stack;
	init->max_elem = stack;
	init->min_last_elem = stack;
	init->max_last_elem = stack;
	init->min_indx = 1;
	init->max_indx = lst_group_len(stack);
}

void			indexing_list(t_stk *stack)
{
	t_init init;

	init_init(stack, &init);
	while (1)
	{
		find_min_max_by_num(stack, &init);
		if (need_break(&init))
			break ;
		find_notindexed_elem(stack, &init);
	}
}
