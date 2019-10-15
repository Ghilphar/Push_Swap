/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Best_combination.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:59:37 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 11:59:59 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	choose_ra_rb(t_start *start)
{
	start->operations_tmp->rra = 0;
	start->operations_tmp->rrb = 0;
	merge_rr_rrr(start);
	total_operations(start);
}

void	choose_rra_rrb(t_start *start)
{
	start->operations_tmp->ra = 0;
	start->operations_tmp->rb = 0;
	merge_rr_rrr(start);
	total_operations(start);
}

void	choose_ra_rrb(t_start *start)
{
	start->operations_tmp->rb = 0;
	start->operations_tmp->rra = 0;
	total_operations(start);
}

void	choose_rra_rb(t_start *start)
{
	start->operations_tmp->ra = 0;
	start->operations_tmp->rrb = 0;
	total_operations(start);
}

void	good_combination(t_start *start)
{
	int		ra_rb;
	int		rra_rrb;
	int		ra_rrb;
	int		rra_rb;

	if (start->operations_tmp->ra < start->operations_tmp->rb)
		ra_rb = start->operations_tmp->rb;
	else
		ra_rb = start->operations_tmp->ra;
	if (start->operations_tmp->rra < start->operations_tmp->rrb)
		rra_rrb = start->operations_tmp->rrb;
	else
		rra_rrb = start->operations_tmp->rra;
	ra_rrb = start->operations_tmp->ra + start->operations_tmp->rrb;
	rra_rb = start->operations_tmp->rra + start->operations_tmp->rb;
	if (ra_rb <= rra_rrb && ra_rb <= ra_rrb && ra_rb <= rra_rb)
		choose_ra_rb(start);
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
		choose_rra_rrb(start);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rrb && ra_rrb <= rra_rb)
		choose_ra_rrb(start);
	else if (rra_rb <= ra_rb && rra_rb <= rra_rrb && rra_rb <= ra_rrb)
		choose_rra_rb(start);
}