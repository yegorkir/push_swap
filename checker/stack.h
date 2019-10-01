//
// Created by yas on 9/30/19.
//

#ifndef CHECKER_STACK_H
# include <stdlib.h>

typedef struct	s_stack
{
	int 			number;
	struct s_stack	*next;
}				t_stack;



t_stack			*create(char *number);
_Bool			push_front(t_stack **head, t_stack *new);
void			clear_list(t_stack **head);

void	swap(t_stack **head);
void	push(t_stack **dst, t_stack **src);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);

long long		ft_ll_atoi(const char *str);
#define CHECKER_STACK_H

#endif //CHECKER_STACK_H
