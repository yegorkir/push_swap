#include <stdio.h>
#include "checker.h"

void	go_exit(_Bool ko)
{
	if (ko)
		ft_putendl("KO");
	exit (1);
}




int read_n_execute(char *input, t_stack **a, t_stack **b)
{

	while (get_next_line(0, &input) > 0)
	{
		if (!*input)
			break;
		parsing_rule(input, a, b);
		//printf("--%s--\n", input);
	}
	return (0);
}

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


	clear_list(&a);
	return 0;
}