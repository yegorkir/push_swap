//
// Created by yas on 9/30/19.
//

#include "checker.h"
#include <limits.h>

void	clear_list(t_stack **head)
{
	t_stack *prev;

	if (!head || !*head)
		exit (1);
	prev = *head;
	*head = (*head)->next;
	while (*head)
	{
		free(prev);
		prev = *head;
		*head = (*head)->next;
	}
	free(prev);
	exit (2);
}

t_stack *create(char *number)
{
	t_stack *new;
	long long num;
	int i;

	i = 0;
	while (number[i])
		if (!ft_isdigit((int)number[i++]))
			return (NULL);
	if(!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (((num = ft_ll_atoi(number)) > INT_MAX) || (num < INT_MIN))
		return (NULL);
	new->number = num;
	return (new);
}

_Bool push_front(t_stack **head, t_stack *new)
{
	if (!head)
		return (0);
	if (!new)
		clear_list(head);
	if (*head)
		new->next = *head;
	*head = new;
	return (1);
}
