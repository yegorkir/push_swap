/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:35:48 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:35:54 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		clear_list(t_stk **head)
{
	t_stk *prev;

	if (!head || !*head)
		return (0);
	prev = *head;
	*head = (*head)->next;
	while (*head)
	{
		free(prev);
		prev = *head;
		*head = (*head)->next;
	}
	free(prev);
	return (1);
}

t_stk	*create(char *number)
{
	t_stk *new;
	long long num;
	int i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
		if (!ft_isdigit((int)number[i++]))
			return (NULL);
	if (!(new = (t_stk*)malloc(sizeof(t_stk))))
		return (NULL);
	if (((num = ft_ll_atoi(number)) > 2147483647) || (num < -2147483648))
		return (NULL);
	new->number = num;
	new->depth = 0;
	new->index = 0;
	new->stack_name = 'a';
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

_Bool	push_front(t_stk **head, t_stk *new)
{
	if (!head)
		return (0);
	if (!new)
		clear_list(head);
	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	*head = new;
	return (1);
}

void	check_doubles(t_stk **stack)
{
	t_stk *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
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
}