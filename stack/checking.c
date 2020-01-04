/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_descending.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 21:50:46 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 21:50:47 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stack.h"

_Bool	check_ascending(t_stk *stack, int n)
{
	int prev;
	int i;

	if (!stack)
		return (1);
	prev = stack->number;
	stack = stack->next;
	i = 1;
	while (stack && (!n || i < n))
	{
		if (stack->number < prev)
			return (0);
		prev = stack->number;
		stack = stack->next;
		i++;
	}
	return (1);
}

_Bool	check_descending(t_stk *stack, int n)
{
	int prev;
	int i;

	if (!stack)
		return (1);
	prev = stack->number;
	stack = stack->next;
	i = 1;
	while (stack && (!n || i < n))
	{
		if (stack->number > prev)
			return (0);
		prev = stack->number;
		stack = stack->next;
		i++;
	}
	return (1);
}

int		check_doubles(t_stk **stack)
{
	t_stk *tmp;

	if (!stack)
		return (0);
	else if (!*stack || !(*stack)->next)
		return (1);
	tmp = (*stack)->next;
	while (tmp)
	{
		if ((*stack)->number == tmp->number)
		{
			clear_list(stack);
			go_exit(1);
		}
		tmp = tmp->next;
	}
	return (1);
}