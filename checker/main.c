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

void parsing_rule(char *rule, t_stack *a, t_stack *b)
{
    if (!ft_strcmp(rule, "sa"))
        swap(&a);
    else if (!ft_strcmp(rule, "sb"))
        swap(&b);
    else if (!ft_strcmp(rule, "ss"))
    {
        swap(&a);
        swap(&b);
    }
    else if (!ft_strcmp(rule, "pa"))
        push(&a, &b);
    else if (!ft_strcmp(rule, "pb"))
        push(&b, &a);
    else if (!ft_strcmp(rule, "ra"))
        rotate(&a);
    else if (!ft_strcmp(rule, "rb"))
        rotate(&b);
    else if (!ft_strcmp(rule, "rr"))
    {
       rotate(&a);
       rotate(&b);
    }
    else if (!ft_strcmp(rule, "rra"))
        reverse_rotate(&a);
    else if (!ft_strcmp(rule, "rrb"))
        reverse_rotate(&b);
    else if (!ft_strcmp(rule, "rrr"))
    {
        reverse_rotate(&a);
        reverse_rotate(&b);
    }
    ////else stop&return KO
}

int read_n_execute(char *input, t_stack *a, t_stack *b)
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

	if (ac < 2)
		go_exit(0);

	a = NULL;
	while (ac > 1)
		push_front(&a, create(av[--ac]));
    read_n_execute(line, NULL, NULL);


	clear_list(&a);
	return 0;
}