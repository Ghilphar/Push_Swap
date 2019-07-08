/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:45:39 by fgaribot          #+#    #+#             */
/*   Updated: 2019/07/08 17:28:52 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_start *start)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	first = start->list_a;
	second = first->next;
	last = first;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	start->list_a = second;
}

void	rotate_b(t_start *start)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	first = start->list_b;
	second = first->next;
	last = first;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	start->list_b = second;
}

void	rotate_r(t_start *start)
{
	rotate_a(start);
	rotate_b(start);
}
