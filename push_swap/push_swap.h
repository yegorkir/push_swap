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

void mid_min_max_a(t_stk **stack);
void mid_max_min_a(t_stk **stack);
void min_max_mid_a(t_stk **stack);
void max_min_mid_a(t_stk **stack);
void max_mid_min_a(t_stk **stack);

void min_mid_max_second(t_stk **a, t_stk **b);
void max_min_mid_second(t_stk **a, t_stk **b);
void min_max_mid_second(t_stk **a, t_stk **b);
void mid_max_min_second(t_stk **a, t_stk **b);
void mid_min_max_second(t_stk **a, t_stk **b);

void min_mid_max_first(t_stk **a, t_stk **b);
void max_min_mid_first(t_stk **a, t_stk **b);
void min_max_mid_first(t_stk **a, t_stk **b);
void mid_max_min_first(t_stk **a, t_stk **b);
void mid_min_max_first(t_stk **a, t_stk **b);

void	push_group(t_stk **dst, t_stk **src);


int		find_min_max(t_stk *stack, int *min);
int		find_min_max_by_num(t_stk *stack, t_init *init);
int		lst_group_len(t_stk * stack);
int		find_thirds(t_stk *stack, int *third, int *two_thirds);

void 	indexing_list(t_stk *stack);

void 	choose_stack_sort_in_three_groups(t_stk **first, t_stk **second, char name_from);
void	sort_in_three_groups(t_stk **from, t_stk **to, char name_from);


void	sorter(t_stk **first, t_stk **second);

void sort_triples(t_stk **a, t_stk **b);

#endif //CHECKER_PUSH_SWAP_H
