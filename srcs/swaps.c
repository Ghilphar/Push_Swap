/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:43:58 by fgaribot          #+#    #+#             */
/*   Updated: 2019/07/08 17:28:50 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_start *start)
{
	t_stack	*first;
	t_stack	*second;

	if (start->list_a != NULL && (start->list_a)->next != NULL)
	{
		first = start->list_a;
		second = (start->list_a)->next;
		first->next = second->next;
		second->next = first;
		start->list_a = second;
	}
}

void	swap_b(t_start *start)
{
	t_stack	*first;
	t_stack	*second;

	if (start->list_b != NULL && (start->list_b)->next != NULL)
	{
		first = start->list_b;
		second = (start->list_b)->next;
		first->next = second->next;
		second->next = first;
		start->list_b = second;
	}
}

void	swap_s(t_start *start)
{
	swap_a(start);
	swap_b(start);
}
