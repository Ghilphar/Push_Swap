/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_total_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:00:41 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 17:26:19 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	merge_rr(t_start *start)
{
	if (start->operations_tmp->ra <= start->operations_tmp->rb)
	{
		start->operations_tmp->rr = start->operations_tmp->ra;
		start->operations_tmp->ra = 0;
		start->operations_tmp->rb = start->operations_tmp->rb -
		start->operations_tmp->rr;
	}
	else
	{
		start->operations_tmp->rr = start->operations_tmp->rb;
		start->operations_tmp->rb = 0;
		start->operations_tmp->ra = start->operations_tmp->ra -
		start->operations_tmp->rr;
	}
}

void	merge_rr_rrr(t_start *start)
{
	merge_rr(start);
	if (start->operations_tmp->rra <= start->operations_tmp->rrb)
	{
		start->operations_tmp->rrr = start->operations_tmp->rra;
		start->operations_tmp->rra = 0;
		start->operations_tmp->rrb = start->operations_tmp->rrb -
		start->operations_tmp->rrr;
	}
	else
	{
		start->operations_tmp->rrr = start->operations_tmp->rrb;
		start->operations_tmp->rrb = 0;
		start->operations_tmp->rra = start->operations_tmp->rra -
		start->operations_tmp->rrr;
	}
}

void	total_operations(t_start *start)
{
	start->operations_tmp->total = start->operations_tmp->ra
	+ start->operations_tmp->rb + start->operations_tmp->rra +
	start->operations_tmp->rrb + start->operations_tmp->rr +
	start->operations_tmp->rrr;
}

void	ft_reset_operations(t_nb_operations *nb_operations)
{
	nb_operations->ra = 0;
	nb_operations->rb = 0;
	nb_operations->rr = 0;
	nb_operations->rra = 0;
	nb_operations->rrb = 0;
	nb_operations->rrr = 0;
	nb_operations->total = 0;
}
