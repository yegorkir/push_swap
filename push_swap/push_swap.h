//
// Created by Mort Deanne on 06/12/2019.
//

#ifndef CHECKER_PUSH_SWAP_H
#define CHECKER_PUSH_SWAP_H

#include "../checker/stack.h"


typedef struct	s_init
{
	t_stack	*min_elem;
	t_stack	*max_elem;
	t_stack	*min_last_elem;
	t_stack	*max_last_elem;
	int		min_indx;
	int		max_indx;
}				t_init;


/*
** basic_3_algorithms
*/

void	mid_min_max(t_stack **stack, char name_stack);
void	mid_max_min(t_stack **stack, char name_stack);
void	min_max_mid(t_stack **stack, char name_stack);
void	max_min_mid(t_stack **stack, char name_stack);
void	max_mid_min(t_stack **stack, char name_stack);




int		find_min_max(t_stack *stack, int *min);
int		find_min_max_by_num(t_stack *stack, t_init *init);
int		lst_len(t_stack * stack);
int		find_thirds(int min, int max, int *third, int *two_thirds);

void 	indexing_list(t_stack *stack);


#endif //CHECKER_PUSH_SWAP_H
