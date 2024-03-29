/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <mdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:32:07 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:35:43 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		push_swap_ll_atoi(const char *str)
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
		if (res != ((res * 10 + (int)(*str - '0')) / 10))
			return (1844674407370955161);
		res = res * 10 + (int)(*str++ - '0');
	}
	return (negative * res);
}
