/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:46:07 by fgaribot          #+#    #+#             */
/*   Updated: 2019/07/08 17:28:53 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_a(t_start *start)
{
	t_stack	*last;
	t_stack	*penultimate;

	last = start->list_a;
	penultimate = start->list_a;
	while ((penultimate->next)->next != NULL)
		penultimate = penultimate->next;
	while (last->next != NULL)
		last = last->next;
	penultimate->next = NULL;
	last->next = start->list_a;
	start->list_a = last;
}

void	reverse_rotate_b(t_start *start)
{
	t_stack	*last;
	t_stack	*penultimate;

	last = start->list_b;
	penultimate = start->list_b;
	while ((penultimate->next)->next != NULL)
		penultimate = penultimate->next;
	while (last->next != NULL)
		last = last->next;
	penultimate->next = NULL;
	last->next = start->list_b;
	start->list_b = last;
}

void	reverse_rotate_r(t_start *start)
{
	reverse_rotate_a(start);
	reverse_rotate_b(start);
}
