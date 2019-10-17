/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:40:18 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/17 17:16:05 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		correct_place(t_start *start, int nb)
{
	int			i;
	t_stack		*tmp_1;
	t_stack		*tmp_2;
	t_stack		*last;

	i = 0;
	tmp_1 = start->list_b;
	tmp_2 = tmp_1->next;
	last = start->list_b;
	if (0 == possibli_first_place(start, nb))
		return (0);
	i = place_on_b(start, nb);
	return (i);
}

int		possibli_first_place(t_start *start, int nb)
{
	t_stack		*tmp_1;
	t_stack		*tmp_2;
	t_stack		*last;

	tmp_1 = start->list_b;
	tmp_2 = tmp_1->next;
	last = start->list_b;
	while (last->next != NULL)
		last = last->next;
	//if ((nb < last->nb && nb < tmp_1->nb) && tmp_1->nb < last->nb &&
	//nb > start->data->min_list_b)
	if ((nb < last->nb && nb < tmp_1->nb) && tmp_1->nb > last->nb &&
	nb < start->data->min_list_b)
		return (0);
	//if ((nb < tmp_1->nb && nb > last->nb && tmp_1->nb > last->nb) ||
	//(nb > tmp_1->nb && nb < last->nb && tmp_1->nb > last->nb))
	if ((nb < tmp_1->nb && nb > last->nb && tmp_1->nb < last->nb) ||
	(nb > tmp_1->nb && nb < last->nb && tmp_1->nb < last->nb))
		return (0);
	//if ((nb > tmp_1->nb && nb < last->nb) && tmp_1->nb > last->nb &&
	//nb < start->data->max_list_b)
	if ((nb > tmp_1->nb && nb < last->nb) && tmp_1->nb < last->nb &&
	nb > start->data->max_list_b)
		return (0);
	return (1);
}

void	ft_algo(t_start *start)
{
	t_stack		*tmp;
	int			i;

	ft_underaction(start);
	tmp = start->list_a;
	while (tmp != NULL)
	{
		i = 0;
		start->data->first_total = 0;
		ft_reset_operations(start->operations_to_do);
		while (tmp != NULL)
		{
			i++;
			start->data->place_on_b = correct_place(start, tmp->nb);
			ft_calcul_operations(i, start);
			tmp = tmp->next;
		}
		exec_operations(start);
		tmp = start->list_a;
	}
	rotate_final_b(start);
	final_push_a(start);
}
