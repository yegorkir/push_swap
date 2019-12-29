//
// Created by yas on 9/30/19.
//

#ifndef CHECKER_STACK_H
# include <stdlib.h>

typedef struct	s_stk
{
	int 			number;
	int 			index;
	int				depth;
	_Bool			is_sort;
	char 			stack_name;
	struct s_stk	*next;
	struct s_stk	*prev;
}				t_stk;



t_stk			*create(char *number);
_Bool			push_front(t_stk **head, t_stk *new);
void			clear_list(t_stk **head);

void			swap_ch(t_stk **head);
void			push_ch(t_stk **dst, t_stk **src);
void			rotate_ch(t_stk **head);
void			reverse_rotate_ch(t_stk **head);

_Bool check_descending(t_stk *stack, int n);
_Bool check_ascending(t_stk *stack, int n);



void	go_exit(_Bool ko);

long long		ft_ll_atoi(const char *str);
#define CHECKER_STACK_H

#endif //CHECKER_STACK_H
