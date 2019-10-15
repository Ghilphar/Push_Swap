/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operate_Pushs_sa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:54:39 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 12:03:24 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "checker.h"

void	Operate_sa(t_start *start)
{
	rotate_a(start);
	write(1, "sa\n", 3);
}

void	Operate_pa(t_start *start, int i)
{
	while (i-- > 0)
	{
		push_a(start);
		write(1,"pa\n", 3);
	}
}

void	Operate_pb(t_start *start, int i)
{
	while (i-- > 0)
	{
		push_b(start);
		write(1,"pb\n", 3);
	}
}

void	Final_Push_a(t_start *start)
{
	Operate_pa(start, start->data->nb_list_b);
}