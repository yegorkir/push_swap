//
// Created by yas on 9/30/19.
//

#include "ft_stack.h"

#include <stdio.h>

void	swap_ch(t_stk **head)
{
	t_stk *prev;

	if (head && *head && (*head)->next)
	{
		prev = *head;
		*head = (*head)->next;
		prev->next = (*head)->next;
		(*head)->next = prev;
	}
}

void	push_ch(t_stk **dst, t_stk **src)
{
	t_stk *src_next;

	if (dst && src && *src)
	{
		src_next = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = src_next;
	}
}

void	rotate_ch(t_stk **head)
{
	t_stk *tail;

	if (head && *head && (*head)->next)
	{
		tail = *head;
		while (tail->next)
			tail = tail->next;
		tail->next = *head;
		*head = (*head)->next;
		tail->next->next = NULL;
	}
}

void	reverse_rotate_ch(t_stk **head)
{
	t_stk *second;
	t_stk *pretail;

	if (head && *head && (*head)->next)
	{
		pretail = *head;
		second = *head;
		while (pretail->next->next)
			pretail = pretail->next;
		*head = pretail->next;
		pretail->next = NULL;
		(*head)->next = second;
	}
}

