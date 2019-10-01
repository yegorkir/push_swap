#include <stdio.h>
#include "checker.h"

void	go_exit(_Bool ko)
{
	if (ko)
		ft_putendl("KO");
	exit (1);
}

int main(int ac, char **av)
{
	t_stack	*a = NULL;
	t_stack *b = NULL;

	if (ac < 1)
		go_exit(0);

	a = NULL;
	while (ac > 1)
		push_front(&a, create(av[--ac]));
	swap(&a);
	push(&b, &a);
	rotate(&a);
	rotate(&b);
	reverse_rotate(&a);
	reverse_rotate(&b);

	clear_list(&a);
	return 0;
}