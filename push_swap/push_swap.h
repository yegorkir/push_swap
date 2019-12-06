//
// Created by Mort Deanne on 06/12/2019.
//

#ifndef CHECKER_PUSH_SWAP_H
#define CHECKER_PUSH_SWAP_H

#include "../checker/stack.h"

/*
** basic_3_algorithms
*/

void	mid_min_max(t_stack **stack, char name_stack);
void	mid_max_min(t_stack **stack, char name_stack);
void	min_max_mid(t_stack **stack, char name_stack);
void	max_min_mid(t_stack **stack, char name_stack);
void	max_mid_min(t_stack **stack, char name_stack);



int		find_thirds(int min, int max, int *third, int *two_thirds);
int		find_min_max(t_stack *stack, int *min);

void 	indexing_list(t_stack *stack);


#endif //CHECKER_PUSH_SWAP_H
