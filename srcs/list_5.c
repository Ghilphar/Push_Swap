/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:51:21 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/16 20:17:47 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	max_to_list_b(t_start *start)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = start->list_a;
	while (tmp->nb != start->data->max_list_a)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 3)
		operate_ra(start, i);
	else
		operate_rra(start, 4 - i);
	operate_pb(start, 1);
}

void	min_to_list_b(t_start *start)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = start->list_a;
	while (tmp->nb != start->data->min_list_a)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 3)
		operate_ra(start, i);
	else
		operate_rra(start, 5 - i);
	operate_pb(start, 1);
}

void	list_5(t_start *start)
{
	list_extrema_a(start);
	min_to_list_b(start);
	max_to_list_b(start);
	list_3(start);
	operate_pa(start, 1);
	operate_ra(start, 1);
	operate_pa(start, 1);
}

void	little_list(t_start *start)
{
	if (start->data->nb_list_a == 3)
		list_3(start);
	else
		list_5(start);
	return ;
}
