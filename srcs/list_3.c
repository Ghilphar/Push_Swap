/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:49:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/16 20:17:16 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_max_bottom(t_start *start)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = start->list_a;
	while (tmp->nb != start->data->max_list_a)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == 0)
		operate_ra(start, 1);
	else if (i == 1)
		operate_rra(start, 1);
}

void	rotate_min_top(t_start *start)
{
	t_stack *tmp;

	tmp = start->list_a;
	if (tmp->nb != start->data->min_list_a)
		operate_sa(start);
}

void	list_3(t_start *start)
{
	list_extrema_a(start);
	rotate_max_bottom(start);
	rotate_min_top(start);
}
