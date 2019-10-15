/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Correct_Place_on_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:42:37 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 16:43:08 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		nb_sup_max(t_start *start, int nb)
{
	int			i;
	t_stack		*tmp_1;
	t_stack		*tmp_2;

	i = 0;
	tmp_1 = start->list_b;
	tmp_2 = tmp_1->next;
	while (tmp_1->nb != start->data->min_list_b)
	{
		i++;
		tmp_1 = tmp_1->next;
	}
	return (i);
}

int		nb_inf_min(t_start *start, int nb)
{
	int			i;
	t_stack		*tmp_1;
	t_stack		*tmp_2;

	i = 0;
	tmp_1 = start->list_b;
	tmp_2 = tmp_1->next;
	while (tmp_1->nb != start->data->min_list_b)
	{
		i++;
		tmp_1 = tmp_1->next;
	}
	return (i);
}

int		nb_inf_max_sup_min(t_start *start, int nb)
{
	int			i;
	t_stack		*tmp_1;
	t_stack		*tmp_2;

	i = 0;
	tmp_1 = start->list_b;
	tmp_2 = tmp_1->next;
	i++;
	while ((nb > tmp_1->nb && nb > tmp_2->nb) || (nb < tmp_1->nb && nb < tmp_2->nb) || (nb < tmp_1->nb && nb > tmp_2->nb))
	{
		i++;
		tmp_1 = tmp_1->next;
		tmp_2 = tmp_2->next;
	}
	return (i);
}

int		Place_on_b(t_start *start, int nb)
{
	int			i;

	i = 0;
	if (nb > start->data->max_list_b)
		i = nb_sup_max(start, nb);
	else if (nb < start->data->min_list_b)
		i = nb_inf_min(start, nb);
	else
		i = nb_inf_max_sup_min(start, nb);
	return (i);
}
