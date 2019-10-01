/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <mdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:32:07 by mdeanne           #+#    #+#             */
/*   Updated: 2019/04/08 20:31:48 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long		ft_ll_atoi(const char *str)
{
	int			negative;
	long long	res;

	res = 0;
	negative = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		res = res * 10 + (int)(*str++ - '0');
	}
	return (negative * (int)res);
}
