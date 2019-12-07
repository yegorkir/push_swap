//
// Created by Mort Deanne on 06/12/2019.
//

#ifndef CHECKER_PUSH_SWAP_H
#define CHECKER_PUSH_SWAP_H

#include "../checker/stack.h"
#define ABS(x) ((x<0)?(-x):(x))

typedef struct	s_init
{
	t_stack	*min_elem;
	t_stack	*max_elem;
	t_stack	*min_last_elem;
	t_stack	*max_last_elem;
	int		min_indx;
	int		max_indx;
}				t_init;


void	swap(t_stack **head);
void	push(t_stack **dst, t_stack **src);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);

/*
** basic_3_algorithms
*/

void mid_min_max(t_stack **stack);
void mid_max_min(t_stack **stack);
void min_max_mid(t_stack **stack);
void max_min_mid(t_stack **stack);
void max_mid_min(t_stack **stack);




int		find_min_max(t_stack *stack, int *min);
int		find_min_max_by_num(t_stack *stack, t_init *init);
int		lst_group_len(t_stack * stack);
int		find_thirds(t_stack *stack, int *third, int *two_thirds);

void 	indexing_list(t_stack *stack);

void 	choose_stack_sort_in_three_groups(t_stack **first, t_stack **second, char name_from);
void	sort_in_three_groups(t_stack **from, t_stack **to, char name_from);


void	sorter(t_stack **first, t_stack **second);

#endif //CHECKER_PUSH_SWAP_H
