//
// Created by mdeanne on 10/9/19.
//

#include "stack.h"
#include "../libft/libft.h"

_Bool if_swap(char *rule, t_stack **a, t_stack **b)
{
    if (!ft_strcmp(rule, "sa"))
        swap(a);
    else if (!ft_strcmp(rule, "sb"))
        swap(b);
    else if (!ft_strcmp(rule, "ss"))
    {
        swap(a);
        swap(b);
    }
	else
		return (1);
	return (0);
}

_Bool if_push(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(rule, "pa"))
		push(a, b);
	else if (!ft_strcmp(rule, "pb"))
		push(b, a);
	else
		return (1);
	return (0);
}

_Bool if_rotate(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(rule, "ra"))
	rotate(a);
	else if (!ft_strcmp(rule, "rb"))
		rotate(b);
	else if (!ft_strcmp(rule, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else
		return (1);
	return (0);
}

_Bool if_reverse_rotate(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(rule, "rra"))
		reverse_rotate(a);
	else if (!ft_strcmp(rule, "rrb"))
		reverse_rotate(b);
	else if (!ft_strcmp(rule, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (1);
	return (0);
}

void perform_rule(char *rule, t_stack **a, t_stack **b)
{
	if(if_swap(rule, a, b) && if_push(rule, a, b) &&
			if_rotate(rule, a, b) && if_reverse_rotate(rule, a, b))
	{
		clear_list(a);
		clear_list(b);
		go_exit(1);
	}
    ////else stop&free&return KO
}