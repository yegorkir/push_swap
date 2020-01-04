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

void	fill_stack_by_complex_arg(t_stk **stack, char *arg)
{
	char *tmp;

	while (*arg && (tmp = ft_strrchr(arg, ' ')))
	{
		if (*(tmp + 1))
		{
			if (!push_front(stack, create(tmp + 1)))
			{
				clear_list(stack);
				go_exit(1);
			}
			check_doubles(stack);
		}
		*tmp = '\0';
	}
}

void	fill_stack(t_stk **stack, int ac, char **av)
{
	while (ac > 1)
	{
		if (ft_is_complex_string(av[--ac], ' '))
			fill_stack_by_complex_arg(stack, av[ac]);
		else if (!push_front(stack, create(av[ac])) && check_doubles(stack))
		{
			clear_list(stack);
			go_exit(1);
		}
	}
}