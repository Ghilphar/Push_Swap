/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operate_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:55:18 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 12:04:28 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	Operate_ra(t_start *start, int i)
{
	while (i-- > 0)
	{
		rotate_a(start);
		write(1, "ra\n", 3);
	}
}

void	Operate_rb(t_start *start, int i)
{
	while (i-- > 0)
	{
		rotate_b(start);
		write(1, "rb\n", 3);
	}
}

void	Operate_rr(t_start *start, int i)
{
	while (i-- > 0)
	{
		rotate_r(start);
		write(1, "rr\n", 3);
	}
}

void	Rotate_b(t_start *start)
{
	t_stack *max;
	int		i;

	i = 0;
	max = start->list_b;
	while (max->nb != start->data->max_list_b)
	{
		i++;
		max = max->next;
	}
	if (start->data->nb_list_b < i && (i / start->data->nb_list_b) * 100 <= 50)
		Operate_rb(start, i);
	else
		Operate_rrb(start, start->data->nb_list_b - i);
}