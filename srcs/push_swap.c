/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:53:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 17:31:57 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_start		*start;
	t_stack		*test;

	if (ac < 2)
		return (0);
	if (!(start = malloc(sizeof(t_start))))
		return (0);
	start->list_a = NULL;
	start->list_b = NULL;
	if (!(start->data = malloc(sizeof(t_data))))
		return (0);
	ft_initialise(ac, av, &start);
	ft_double(&start);
	if (test_sorted(start) == 1)
	{
		Clear_leaks_2(start);
		return (0);
	}
	ft_algo(start);
	Clear_leaks(start);
	return (0);
}
