//
// Created by Mort Deanne on 03/12/2019.
//

#include "ft_stack.h"
#include "../checker/checker.h"

void	go_exit(_Bool ko)
{
	if (ko)
		ft_putendl("KO");
	exit (1);
}