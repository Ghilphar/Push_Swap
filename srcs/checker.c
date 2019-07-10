#include "checker.h"

t_stack  *ft_listnew(int nb)
{
    t_stack   *new;

    if (!(new = malloc(sizeof(t_stack))))
        return(NULL);
    new->nb = nb;
    new->next = NULL;
    return (new);
}

void    ft_lstaddend(t_start *start, t_stack *new)
{
	t_stack		*list_a;

	if (!(start->list_a))
		start->list_a = new;
	
	else
	{
		list_a = start->list_a;
		while (list_a->next != NULL)
			list_a = list_a->next;
		list_a->next = new;
	}
	/* 
    t_stack      *tmp;


    tmp = *alist;
    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;*/
}

int		ft_one(char *str)
{
	int			i;

	i = 0;
	while (47 < str[i] && str[i] < 58)
		i++;
	return (str[i] == '\0' ? 1 : 0);
}

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

int		main(int ac, char **av)
{
	t_start		*start;
	t_stack		*tmp;
	char		**tab;
	int			i;

	i = 0;
	if (!(start = malloc(sizeof(t_start))))
		return(0);
	start->list_a = NULL;
	start->list_b = NULL;
	if (ac == 2)
	{
		if (ft_one(av[1]))
		{
			if (ft_isanint(av[1]))
				start->list_a = ft_listnew(atoi(av[1]));
			else
				printf("Error1\n");
		}
		else
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
	}
	/*
	tmp = start->list_a;
	while (tmp != NULL)
	{
		printf("is : %d\n", tmp->nb);
		tmp = tmp->next;
	} */
	return (0);
}

/*
int main()
{
    int i;
    t_start *start;
    t_list  *tmp;

    i = -1;
    start->list_a = ft_lstnew(-1);
    start->list_b = ft_lstnew(11);
    while (i++ < 10)
    {
        tmp = ft_lstnew(i);
        ft_lstaddend(&start->list_a, tmp);
    }
    while (i-- > 0)
    {
        tmp = ft_lstnew(i);
        ft_lstaddend(&start->list_b, tmp);
    }
    reverse_rotate_r(start);
    rotate_r(start);
	push_a(start);
	push_a(start);
	swap_a(start);

    tmp = start->list_a;
    while (tmp != NULL)
    {
        printf("list_a : %d\n", tmp->nb);
        tmp = tmp->next;
    }
    tmp = start->list_b;
    while (tmp != NULL)
    {
        printf("list_b : %d\n", tmp->nb);
        tmp = tmp->next;
    }
    return(0);
}
*/
