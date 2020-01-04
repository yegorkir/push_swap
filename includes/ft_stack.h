/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:35:58 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:36:00 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include <stdlib.h>

typedef struct	s_stk
{
	int				number;
	int				index;
	int				depth;
	_Bool			is_sort;
	char			stack_name;
	struct s_stk	*next;
	struct s_stk	*prev;
}				t_stk;

void fill_stack(t_stk **stack, int ac, char **av);
t_stk			*create(char *number);
_Bool			push_front(t_stk **head, t_stk *new);
int				clear_list(t_stk **head);

int check_doubles(t_stk **stack);
_Bool			check_descending(t_stk *stack, int n);
_Bool			check_ascending(t_stk *stack, int n);

void			go_exit(int ko);

long long		ft_ll_atoi(const char *str);
#endif
