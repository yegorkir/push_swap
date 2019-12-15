//
// Created by mdeanne on 10/9/19.
//

#include "ft_stack.h"
#include "../libft/libft.h"

_Bool if_swap(char *rule, t_stk **a, t_stk **b)
{
    if (!ft_strcmp(rule, "sa"))
		swap_ch(a);
    else if (!ft_strcmp(rule, "sb"))
		swap_ch(b);
    else if (!ft_strcmp(rule, "ss"))
    {
		swap_ch(a);
		swap_ch(b);
    }
	else
		return (1);
	return (0);
}

_Bool if_push(char *rule, t_stk **a, t_stk **b)
{
	if (!ft_strcmp(rule, "pa"))
		push_ch(a, b);
	else if (!ft_strcmp(rule, "pb"))
		push_ch(b, a);
	else
		return (1);
	return (0);
}

_Bool if_rotate(char *rule, t_stk **a, t_stk **b)
{
	if (!ft_strcmp(rule, "ra"))
		rotate_ch(a);
	else if (!ft_strcmp(rule, "rb"))
		rotate_ch(b);
	else if (!ft_strcmp(rule, "rr"))
	{
		rotate_ch(a);
		rotate_ch(b);
	}
	else
		return (1);
	return (0);
}

_Bool if_reverse_rotate(char *rule, t_stk **a, t_stk **b)
{
	if (!ft_strcmp(rule, "rra"))
		reverse_rotate_ch(a);
	else if (!ft_strcmp(rule, "rrb"))
		reverse_rotate_ch(b);
	else if (!ft_strcmp(rule, "rrr"))
	{
		reverse_rotate_ch(a);
		reverse_rotate_ch(b);
	}
	else
		return (1);
	return (0);
}

void perform_rule(char *rule, t_stk **a, t_stk **b)
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