/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:53:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/05 11:09:13 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pivot(t_start *start, t_stack *last)
{
	start->data->pivot = last->nb;
}

void	Operate_pa(t_start *start)
{
	push_a(start);
	write(0,"pa\n", 3);
}

void	ft_split(t_stack *list, t_stack *last, t_start *start)
{
	t_stack		tmp;

	tmp = list;
	ft_pivot(start, t_stack *last);
	while (tmp != NULL)
	{
		if (tmp->nb >= start->data->pivot)
			Operate_pa(start);
	}
}

void    ft_algo(t_start *start)
{
	t_stack		list;
	t_stack		last;

	list = start->list_a;
	last = list;
	while (last->next != NULL)
		last = last->next;
	ft_split(list, last, start);
}


void	ft_add_start(t_stack *new, t_start *start)
{
	new->next = start->data->sorted;
	start->data->sorted = new;
}

void	ft_add_other(t_stack *new, t_start *start)
{
	t_stack		*sort;
	t_stack		*tmp;

	sort = start->data->sorted;
	while (sort != NULL && sort->nb < new->nb)
	{
		tmp = sort;
		sort = sort->next;
	}
	tmp->next = new;
	new->next = sort;
}

void	ft_sort(t_start *start)
{
	t_stack		*tmp;
	t_stack		*new;

	tmp = start->list_a;
	while (tmp != NULL)
	{
		new = ft_new(tmp->nb);
		if (start->data->sorted == NULL)
			start->data->sorted = new;
		else
		{
			if (new->nb < start->data->sorted->nb)
				ft_add_start(new, start);
			else
				ft_add_other(new, start);
		}
		tmp = tmp->next;
	}
}

int     main(int ac, char **av)
{
    t_start *start;
	t_stack *test;

    if (ac < 2)
        return(0);
    if (!(start = malloc(sizeof(t_start))))
        return(0);
    start->list_a = NULL;
    start->list_b = NULL;
	if (!(start->data = malloc(sizeof(t_data))))
		return(0);
	start->data->sorted = NULL;
    ft_initialise(ac, av, &start);
    ft_double(&start);
	ft_sort(start);
	ft_algo(start);

	/*
	test = (start->data)->sorted;
	while (test != NULL)
	{
		printf("%d\n", test->nb);
		test = test->next;
	}
	*/
}