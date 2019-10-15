/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operate_reverse_rotates.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:55:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 11:56:09 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	Operate_rra(t_start *start, int i)
{
	while (i-- > 0)
	{
		reverse_rotate_a(start);
		write(1, "rra\n", 4);
	}
}

void	Operate_rrb(t_start *start, int i)
{
	while (i-- > 0)
	{
		reverse_rotate_b(start);
		write(1, "rrb\n", 4);
	}
}

void	Operate_rrr(t_start *start, int i)
{
	while (i-- > 0)
	{
		reverse_rotate_r(start);
		write(1, "rrr\n", 4);
	}
}