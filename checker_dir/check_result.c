/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:35:14 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:35:18 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stack.h"

void	check_result(t_stk **a, t_stk **b)
{
	if (*b || !check_ascending(*a, 0))
	{
		clear_list(a);
		clear_list(b);
		go_exit(1);
	}
}
