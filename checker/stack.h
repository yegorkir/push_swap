//
// Created by yas on 9/30/19.
//

#ifndef CHECKER_STACK_H
# include <stdlib.h>

typedef struct	s_stack
{
	int 			number;
	int 			index;
	int				depth;
	char 			stack_name;
	struct s_stack	*next;
}				t_stack;



t_stack			*create(char *number);
_Bool			push_front(t_stack **head, t_stack *new);
void			clear_list(t_stack **head);

void			swap_ch(t_stack **head);
void			push_ch(t_stack **dst, t_stack **src);
void			rotate_ch(t_stack **head);
void			reverse_rotate_ch(t_stack **head);

_Bool check_descending(t_stack *stack, int n);
_Bool check_ascending(t_stack *stack, int n);



void	go_exit(_Bool ko);

long long		ft_ll_atoi(const char *str);
#define CHECKER_STACK_H

#endif //CHECKER_STACK_H
