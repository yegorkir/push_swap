//
// Created by Mort Deanne on 06/12/2019.
//

#ifndef CHECKER_PUSH_SWAP_H
#define CHECKER_PUSH_SWAP_H

#include "ft_stack.h"


typedef struct	s_init
{
	t_stk	*min_elem;
	t_stk	*max_elem;
	t_stk	*min_last_elem;
	t_stk	*max_last_elem;
	int		min_indx;
	int		max_indx;
}				t_init;

typedef struct	s_part
{
	int min;
	int max;
	int len;
}				t_part;

void	swap(t_stk **head);
void	push(t_stk **dst, t_stk **src);
void	rotate(t_stk **head);
void	reverse_rotate(t_stk **head);

/*
** basic_3_algorithms
*/

void mid_min_max_a_top(t_stk **stack);
void mid_max_min_a_top(t_stk **stack);
void min_max_mid_a_top(t_stk **stack);
void max_min_mid_a_top(t_stk **stack);
void max_mid_min_a_top(t_stk **stack);

void min_mid_max_b_top(t_stk **a, t_stk **b);
void max_min_mid_b_top(t_stk **a, t_stk **b);
void min_max_mid_b_top(t_stk **a, t_stk **b);
void mid_max_min_b_top(t_stk **a, t_stk **b);
void mid_min_max_b_top(t_stk **a, t_stk **b);

void min_mid_max_b_bottom(t_stk **a, t_stk **b);
void max_min_mid_b_bottom(t_stk **a, t_stk **b);
void min_max_mid_b_bottom(t_stk **a, t_stk **b);
void mid_max_min_b_bottom(t_stk **a, t_stk **b);
void mid_min_max_b_bottom(t_stk **a, t_stk **b);

void	push_group(t_stk **dst, t_stk **src);
void	reverse_rotate_group(t_stk **stack, t_stk *last_group_stack);

int		find_min_max(t_stk *stack, int *min);
int		find_min_max_by_num(t_stk *stack, t_init *init);
int		lst_group_len(t_stk * stack);
int		find_thirds(t_stk *stack, int *third, int *two_thirds);

void 	indexing_list(t_stk *stack);

void	sort_in_three_groups_a(t_stk **a, t_stk **b);
void	sort_in_three_groups_b(t_stk **a, t_stk **b);


void	sorter(t_stk **first, t_stk **second);

void sort_triples(t_stk **a, t_stk **b);

#endif //CHECKER_PUSH_SWAP_H
