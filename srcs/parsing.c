/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:34:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 20:21:29 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_new(int nb)
{
	t_stack		*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_add(t_start **start, char *num)
{
	t_stack *new;
	t_stack *tmp;

	new = ft_new(ft_atoi(num));
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

void	ft_operate(t_start *start)
{
	char	**line;
	int		ret;

	line = malloc(sizeof(line));
	while ((ret = get_next_line(0, line)) == 1)
	{
		// printf("ret:%d\n", ret);
		if ((ft_strcmp(*line, "sa\n")) == 0 || (ft_strcmp(*line, "sb\n") == 0)
		|| (ft_strcmp(*line, "ss\n") == 0))
			ft_swaps(*line, start);
		else if ((ft_strcmp(*line, "pa\n") == 0) || (ft_strcmp(*line, "pb\n") == 0))
			ft_pushs(*line, start);
		else if ((ft_strcmp(*line, "ra\n") == 0) || (ft_strcmp(*line, "rb\n") == 0)
		|| (ft_strcmp(*line, "rr\n") == 0))
			ft_rotates(*line, start);
		else if ((ft_strcmp(*line, "rra\n") == 0) ||
		(ft_strcmp(*line, "rrb\n") == 0)
		|| (ft_strcmp(*line, "rrr\n") == 0))
			ft_reverse_rotates(*line, start);
		else
		{
			free(line);
			ft_exit_error(start);
		}
	}
	// printf("ret:%d\n", ret);
	free(line);
}
