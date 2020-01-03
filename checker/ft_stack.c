//
// Created by yas on 9/30/19.
//

#include "checker.h"
#include <limits.h>

void	clear_list(t_stk **head)
{
	t_stk *prev;

	if (!head || !*head)
		//exit (0);
		return ;
	prev = *head;
	*head = (*head)->next;
	while (*head)
	{
		free(prev);
		prev = *head;
		*head = (*head)->next;
	}
	free(prev);
}

t_stk *create(char *number)
{
	t_stk *new;
	long long num;
	int i;

	i = 0;
	while (number[i])
		if (!ft_isdigit((int)number[i++]) && number[i - 1] != '-')
			return (NULL);
	if(!(new = (t_stk*)malloc(sizeof(t_stk))))
		return (NULL);
	if (((num = ft_ll_atoi(number)) > INT_MAX) || (num < INT_MIN))
		return (NULL);
	new->number = num;
	new->depth = 0;
	new->index = 0;
	new->stack_name = 'a';
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

_Bool push_front(t_stk **head, t_stk *new)
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
