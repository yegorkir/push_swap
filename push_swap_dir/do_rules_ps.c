/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rules_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:36:49 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:36:53 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>
#include <libft.h>

void	put_rule(char *rule_name, char stack_name)
{
	write(1, rule_name, ft_strlen(rule_name));
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	swap(t_stk **head)
{
	t_stk *prev;

	if (head && *head && (*head)->next)
	{
		put_rule("s", (*head)->stack_name);
		prev = *head;
		*head = (*head)->next;
		prev->next = (*head)->next;
		(*head)->next = prev;
		if (prev->next)
			prev->next->prev = prev;
		prev->prev = *head;
		(*head)->prev = NULL;
	}
}

void	push(t_stk **dst, t_stk **src)
{
	t_stk *src_next;

	if (dst && src && *src)
	{
		put_rule("p", (*src)->stack_name == 'a' ? 'b' : 'a');
		(*src)->stack_name = ((*src)->stack_name == 'a') ? 'b' : 'a';
		src_next = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = src_next;
		if (*src)
			(*src)->prev = NULL;
		if ((*dst)->next)
			(*dst)->next->prev = *dst;
	}
}

void	rotate(t_stk **head)
{
	t_stk *tail;

	if (head && *head && (*head)->next)
	{
		put_rule("r", (*head)->stack_name);
		tail = *head;
		while (tail->next)
			tail = tail->next;
		tail->next = *head;
		*head = (*head)->next;
		tail->next->next = NULL;
		if (tail->next)
			tail->next->prev = tail;
		(*head)->prev = NULL;
	}
}

void	reverse_rotate(t_stk **head)
{
	t_stk *second;
	t_stk *pretail;

	if (head && *head && (*head)->next)
	{
		put_rule("rr", (*head)->stack_name);
		pretail = *head;
		second = *head;
		while (pretail->next->next)
			pretail = pretail->next;
		*head = pretail->next;
		pretail->next = NULL;
		(*head)->next = second;
		second->prev = *head;
		(*head)->prev = NULL;
	}
}
