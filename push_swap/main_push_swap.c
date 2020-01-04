/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:37:17 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:37:20 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stk	*a;
	t_stk	*b;

	if (ac < 2)
		go_exit(1);
	b = NULL;
	a = NULL;
	while (ac > 1)
	{
		push_front(&a, create(av[--ac]));
		check_doubles(&a);
	}
	indexing_list(a);
	sorter(&a, &b);
	clear_list(&a);
	return (0);
}
