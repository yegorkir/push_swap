/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:36:09 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:36:15 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int ac, char **av)
{
	t_stk	*a;
	t_stk	*b;
	char	*line;

	if (ac < 2)
		go_exit(1);
	a = NULL;
	b = NULL;
	line = NULL;
	while (ac > 1)
	{
		push_front(&a, create(av[--ac]));
		check_doubles(&a);
	}
	read_n_execute(line, &a, &b);
	ft_putendl("OK");
	clear_list(&a);
	return (0);
}
