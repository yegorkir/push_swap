#include "checker.h"


int main(int ac, char **av)
{
	t_stack	*a = NULL;
	t_stack *b = NULL;
	char *line;

	if (ac < 2)
		go_exit(0);

	a = NULL;
	while (ac > 1)
		push_front(&a, create(av[--ac]));
    read_n_execute(line, &a, &b);
	check_result(a, b);
	ft_putendl("OK");
	clear_list(&a);
	return 0;
}