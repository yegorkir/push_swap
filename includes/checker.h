/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:35:26 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:35:28 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_stack.h"

void	perform_rule(char *rule, t_stk **a, t_stk **b);
void	check_result(t_stk **a, t_stk **b);
int		read_n_execute(char *input, t_stk **a, t_stk **b);

void	swap_ch(t_stk **head);
void	push_ch(t_stk **dst, t_stk **src);
void	rotate_ch(t_stk **head);
void	reverse_rotate_ch(t_stk **head);

#endif
