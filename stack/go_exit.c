/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:36:04 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/04 18:36:07 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_stack.h"
#include "../includes/checker.h"

void	go_exit(int ko)
{
	if (ko == 1)
		ft_putendl("KO");
	else if (ko == 2)
		ft_putendl("Error");
	exit(1);
}
