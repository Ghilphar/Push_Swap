/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/08/10 09:18:51 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
				ft_exit_error(*start);
			j++;
		}
	}
}

void	ft_Operate(t_start *start)
{
	char	**line;

	line = malloc(sizeof(line));
	while (get_next_line(0, line) == 1)
	{
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
			free(line);
			ft_exit_error(start);
		}
	}
	free(line);
}

int		main(int ac, char **av)
{
	t_start	*start;

	if (!(start = malloc(sizeof(t_start))))
		return(0);
	start->list_a = NULL;
	start->list_b = NULL;
	if (ac <= 2)
		ft_exit_success(start);
	ft_initialise(ac, av, &start);
	ft_double(&start);
	ft_Operate(start);
	ft_sorted(start);
	ft_exit_success(start);
}
