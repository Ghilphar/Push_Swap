#include "checker.h"

int		ft_isanint(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return(0);
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != 45)
			return (0);
		i++;
		if (i > 11)
			return (0);
	}
	if (i == 11 && (str[0] != '-' || str[1] > '2' || str[10] > '8'))
		return (0);
	if (i == 10 && (str[0] > '2' || str[9] > '7'))
		return (0);
	return (1);
}

/*
int		main(int ac, char **av)
{
	t_start		*start;
	t_stack		*tmp;
	char		**tab;
	int			i;
	Operations_t	Operation[] = {swap_a, swap_b, swap_s, push_a, push_b, rotate_a, rotate_b, rotate_r, reverse_rotate_a, reverse_rotate_b, reverse_rotate_r};

	i = 0;
	if (!(start = malloc(sizeof(t_start))))
		return(0);
	start->list_a = NULL;
	start->list_b = NULL;
	if (ac == 2)
	{
		tab = ft_strsplit(av[1], ' ');
		while (tab[i] != 0)
		{
			if (ft_isanint(tab[i]))
			{
				tmp = ft_listnew(atoi(tab[i]));
				ft_lstaddend(start, tmp);
			}
			else
				printf("Error2\n");
			i++;
		}
	}
	if (ac > 2)
	{
		while (ft_isanint(av[++i]))
		{
			tmp = ft_listnew(atoi(av[i]));
			ft_lstaddend(start, tmp);
		}
		if (i != (ac))
			printf("Error3");
	}
	while (!get_next_line(0, tab))
	{
		if (ft_strcmp(*tab, "sa") == 0)
			i = 0;
		else if (ft_strcmp(*tab, "sb") == 0)
			i = 1;
		else if (ft_strcmp(*tab, "ss") == 0)
			i = 2;
		else if (ft_strcmp(*tab, "pa") == 0)
			i = 3;
		else if (ft_strcmp(*tab, "pb") == 0)
			i = 4;
		else if (ft_strcmp(*tab, "ra") == 0)
			i = 5;
		else if (ft_strcmp(*tab, "rb") == 0)
			i = 6;
		else if (ft_strcmp(*tab, "rr") == 0)
			i = 7;
		else if (ft_strcmp(*tab, "rra") == 0)
			i = 8;
		else if (ft_strcmp(*tab, "rrb") == 0)
			i = 9;
		else if (ft_strcmp(*tab, "rrr") == 0)
			i = 10;
		else
			printf("Error4");
		Operation[i](start);
	}
	return (0);
}
*/

void	ft_add(t_start **start, char *num)
{
	t_stack *new;
	t_stack *tmp;

	if (!(new = malloc(sizeof(t_stack))))
		return;
	new->nb = ft_atoi(num);
	new->next = NULL;
	tmp = (*start)->list_a;
	if (tmp == NULL)
		(*start)->list_a = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_initialise(int ac, char **av, t_start **start)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	while (++i < ac)
	{
		tab = NULL;
		j = 0;
		tab = ft_strsplit(av[i], ' ');
		while (tab[j] != NULL)
		{
			if (ft_isanint(tab[j]) == 1)
				ft_add(start, tab[j]);
			else
				printf("Error5");
			j++;
		}
	}
}

void	ft_double(t_start **start)
{
	t_stack *to_test;
	t_stack *tester;

	to_test = (*start)->list_a;
	while (to_test != NULL)
	{
		tester = to_test->next;
		while (tester != NULL)
		{
			if (tester->nb == to_test->nb)
				printf("ERROR = DOUBLE\n");
			tester = tester->next;
		}
		to_test = to_test->next;
	}
}

void	ft_Operate(t_start *start)
{
	char	**line;
	int		i;
	int		r;

	i = 0;
	while (i == 0 && (r = get_next_line(0, line)) == 1)
	{
		printf("ici");
		if ((ft_strcmp(*line, "sa")) == 0 || (ft_strcmp(*line, "sb") == 0)
		|| (ft_strcmp(*line, "ss") == 0))
			ft_swaps(*line, start);
		else if ((ft_strcmp(*line, "pa") == 0) || (ft_strcmp(*line, "pb") == 0))
			ft_pushs(*line, start);
		else if ((ft_strcmp(*line, "ra") == 0) || (ft_strcmp(*line, "rb") == 0)
		|| (ft_strcmp(*line, "rr") == 0))
			ft_rotates(*line, start);
		else if ((ft_strcmp(*line, "rra") == 0) || (ft_strcmp(*line, "rrb") == 0)
		|| (ft_strcmp(*line, "rrr") == 0))
			ft_reverse_rotates(*line, start);
		else
		{
			i = -1;
			printf("ERROR orders");
		}
	}
}

void	ft_sorted(t_start *start)
{
	int		i;
	t_stack *to_test;
	t_stack *tester;

	i = 0;
	if (start->list_b != NULL)
		printf("KO, b not empty");
	else
	{
		to_test = start->list_a;
		while (i == 0 && to_test != NULL && to_test->next != NULL)
		{
			tester = to_test->next;
			if (to_test->nb > tester->nb)
			{
				printf("KO, non trié");
				i = -1;
			}
			to_test = tester;
		}
	if (i == 0)
		printf("OK");
	}
}

int		main(int ac, char **av)
{
	t_start	*start;

	if (!(start = malloc(sizeof(t_start))))
		return(0);
	start->list_a = NULL;
	start->list_b = NULL;
	ft_initialise(ac, av, &start);
	ft_double(&start);
	ft_Operate(start);
	ft_sorted(start);
}
