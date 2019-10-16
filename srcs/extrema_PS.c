/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrema_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:44:54 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 17:22:14 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	list_extrema_b(t_start *start)
{
	t_stack		*tmp;

	tmp = start->list_b;
	start->data->max_list_b = tmp->nb;
	start->data->min_list_b = tmp->nb;
	while (tmp != NULL)
	{
		if (tmp->nb > start->data->max_list_b)
			start->data->max_list_b = tmp->nb;
		if (tmp->nb < start->data->min_list_b)
			start->data->min_list_b = tmp->nb;
		tmp = tmp->next;
	}
}

void	list_extrema_a(t_start *start)
{
	t_stack		*tmp;

	tmp = start->list_a;
	start->data->max_list_a = tmp->nb;
	start->data->min_list_a = tmp->nb;
	while (tmp != NULL)
	{
		if (tmp->nb > start->data->max_list_a)
			start->data->max_list_a = tmp->nb;
		if (tmp->nb < start->data->min_list_a)
			start->data->min_list_a = tmp->nb;
		tmp = tmp->next;
	}
}
