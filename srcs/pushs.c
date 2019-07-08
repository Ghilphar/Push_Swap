/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:44:47 by fgaribot          #+#    #+#             */
/*   Updated: 2019/07/08 17:28:55 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_a(t_start *start)
{
	t_stack	*to_push;

	if (start->list_b != NULL)
	{
		to_push = start->list_b;
		start->list_b = to_push->next;
		to_push->next = start->list_a;
		start->list_a = to_push;
	}
}

void	push_b(t_start *start)
{
	t_stack	*to_push;

	if (start->list_a != NULL)
	{
		to_push = start->list_a;
		start->list_a = to_push->next;
		to_push->next = start->list_b;
		start->list_b = to_push;
	}
}
