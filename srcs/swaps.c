/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:43:58 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 18:52:51 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swaps(char *line, t_start *start)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_a(start);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_b(start);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_s(start);
}

void	swap_a(t_start *start)
{
	t_stack	*first;
	t_stack	*second;

	if (start->list_a != NULL)
	{
		if ((start->list_a)->next != NULL)
		{
			first = start->list_a;
			second = (start->list_a)->next;
			first->next = second->next;
			second->next = first;
			start->list_a = second;
		}
	}
}

void	swap_b(t_start *start)
{
	t_stack	*first;
	t_stack	*second;

	if (start->list_b != NULL)
	{
		if ((start->list_b)->next != NULL)
		{
			first = start->list_b;
			second = (start->list_b)->next;
			first->next = second->next;
			second->next = first;
			start->list_b = second;
		}
	}
}

void	swap_s(t_start *start)
{
	swap_a(start);
	swap_b(start);
}
