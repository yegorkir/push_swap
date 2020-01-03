//
// Created by yas on 9/30/19.
//

#include "ft_stack.h"

#include <stdio.h>

void	swap(t_stk **head)
{
	t_stk *prev;



	if (head && *head && (*head)->next)
	{
		printf("s%c\n", (*head)->stack_name);
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
		printf("p%c\n", (*src)->stack_name == 'a' ? 'b' : 'a');
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

t_stk *give_tail(t_stk *head)
{
	while(head->next)
		head = head->next;
	return (head);
}

void	rotate(t_stk **head)
{
	t_stk *tail;

	if (head && *head && (*head)->next)
	{
		printf("r%c\n", (*head)->stack_name);
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
		printf("rr%c\n", (*head)->stack_name);
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

