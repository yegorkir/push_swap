//
// Created by yas on 9/30/19.
//

#include "stack.h"

#include <stdio.h>

void	swap(t_stack **head)
{
	t_stack *prev;

	printf("s%c\n", (*head)->stack_name);

	if (head && *head && (*head)->next)
	{
		prev = *head;
		*head = (*head)->next;
		prev->next = (*head)->next;
		(*head)->next = prev;
	}
}

void	push(t_stack **dst, t_stack **src)
{
	t_stack *src_next;

	printf("p%c\n", (*src)->stack_name == 'a' ? 'b' : 'a');

	if (dst && src && *src)
	{
		(*src)->stack_name = ((*src)->stack_name == 'a') ? 'b' : 'a';
		src_next = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = src_next;
	}
}

void	rotate(t_stack **head)
{
	t_stack *tail;

	printf("r%c\n", (*head)->stack_name);

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

void	reverse_rotate(t_stack **head)
{
	t_stack *second;
	t_stack *pretail;

	printf("rr%c\n", (*head)->stack_name);

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

