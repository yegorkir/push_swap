/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dir.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:37:25 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:37:26 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_PUSH_SWAP_H
# define CHECKER_PUSH_SWAP_H
# include "ft_stack.h"

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

typedef struct	s_groups
{
	int		third;
	int		two_thirds;
	int		depth;
}				t_groups;

void			indexing_list(t_stk *stack);

void			sorter(t_stk **a, t_stk **b);
void			sort_in_three_groups(t_stk **a, t_stk **b);
void			sort_triples(t_stk **a, t_stk **b);

/*
** basic_rules_for_push_swap
*/

void			swap(t_stk **head);
void			push(t_stk **dst, t_stk **src);
void			rotate(t_stk **head);
void			reverse_rotate(t_stk **head);

/*
** basic_rules_for_groups_push_swap
*/

void			push_group(t_stk **dst, t_stk **src);
void			reverse_rotate_group(t_stk **stack, t_stk *last_group_stack);
void			set_group_as_sorted(t_stk *a);

/*
** basic_triples_sort_algorithms
*/

void			mid_min_max_a_top(t_stk **a);
void			mid_max_min_a_top(t_stk **a);
void			min_max_mid_a_top(t_stk **a);
void			max_min_mid_a_top(t_stk **stack);
void			max_mid_min_a_top(t_stk **a);

void			min_mid_max_b_top(t_stk **a, t_stk **b);
void			max_min_mid_b_top(t_stk **a, t_stk **b);
void			min_max_mid_b_top(t_stk **a, t_stk **b);
void			mid_max_min_b_top(t_stk **a, t_stk **b);
void			mid_min_max_b_top(t_stk **a, t_stk **b);

void			min_mid_max_b_bottom(t_stk **a, t_stk **b);
void			max_min_mid_b_bottom(t_stk **a, t_stk **b);
void			min_max_mid_b_bottom(t_stk **a, t_stk **b);
void			mid_max_min_b_bottom(t_stk **a, t_stk **b);
void			mid_min_max_b_bottom(t_stk **a, t_stk **b);

void			max_min_mid_a_bottom(t_stk **a);
void			min_max_mid_a_bottom(t_stk **a);
void			mid_max_min_a_bottom(t_stk **a);
void			mid_min_max_a_bottom(t_stk **a);
void			max_mid_min_a_bottom(t_stk **a);

int				find_min_max(t_stk *stack, int *min);
int				find_min_max_by_num(t_stk *stack, t_init *init);
int				find_thirds(t_stk *stack, int *third, int *two_thirds);
t_stk			*find_max_depth_not_sorted_elem(t_stk *a, t_stk *b);
t_stk			*find_last_elem(t_stk *stack);
int				lst_group_len(t_stk *stack);

void			triple_a_top_algo(t_stk **a, t_part *part);
void			triple_a_bottom_algo(t_stk **a, t_stk *last_group_a,
																t_part *part);
void			triple_b_top_algo(t_stk **a, t_stk **b, t_part *part);
void			triple_b_bottom_algo(t_stk **a, t_stk **b, t_stk *last_group_b,
																t_part *part);
#endif
