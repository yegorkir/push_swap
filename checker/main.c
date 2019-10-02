#include <stdio.h>
#include "checker.h"

void	go_exit(_Bool ko)
{
	if (ko)
		ft_putendl("KO");
	exit (1);
}

void	parsing(char *rule, t_stack **a, t_stack **b)
{
	
}

int read_input(char *input)
{

	while (get_next_line(0, &input) > 0)
	{
		if (!*input)
			break;
		printf("--%s--\n", input);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_stack	*a = NULL;
	t_stack *b = NULL;
	char *line;

	if (ac < 1)
		go_exit(0);

	a = NULL;
	while (ac > 1)
		push_front(&a, create(av[--ac]));
	read_input(line);


	clear_list(&a);
	return 0;
}