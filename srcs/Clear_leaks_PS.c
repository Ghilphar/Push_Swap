/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clear_leaks_PS.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:42:24 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 11:44:18 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	Clear_leaks(t_start *start)
{
	t_stack	*to_free;
	t_stack	*next;

	free(start->operations_to_do);
	free(start->operations_tmp);
	free(start->data);
	to_free = start->list_a;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
	to_free = start->list_b;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
}

void	Clear_leaks_2(t_start *start)
{
	t_stack	*to_free;
	t_stack	*next;

	free(start->data);
	to_free = start->list_a;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
	to_free = start->list_b;
	while (to_free != NULL)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
}