/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_n_execute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:36:31 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:36:33 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stack.h"
#include "../includes/checker.h"

int		read_n_execute(char *input, t_stk **a, t_stk **b)
{
	while (get_next_line(0, &input) > 0)
	{
		if (!*input)
		{
			check_result(a, b);
			break ;
		}
		perform_rule(input, a, b);
	}
	return (0);
}
