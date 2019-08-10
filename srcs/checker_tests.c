/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:11:17 by fgaribot          #+#    #+#             */
/*   Updated: 2019/08/10 09:14:43 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_double(t_start **start)
{
	t_stack *to_test;
	t_stack *tester;

	to_test = (*start)->list_a;
	while (to_test != NULL)
	{
		tester = to_test->next;
		while (tester != NULL)
		{
			if (tester->nb == to_test->nb)
				ft_exit_error(*start);
			tester = tester->next;
		}
		to_test = to_test->next;
	}
}

void	ft_sorted(t_start *start)
{
	t_stack *to_test;
	t_stack *tester;

	if (start->list_b != NULL)
		ft_exit_failure(start);
	else
	{
		to_test = start->list_a;
		while (to_test != NULL && to_test->next != NULL)
		{
			tester = to_test->next;
			if (to_test->nb > tester->nb)
				ft_exit_failure(start);
			to_test = tester;
		}
	}
}
