/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/11/04 21:05:05 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_empty(t_start *start)
{
	if (start->list_a == 0)
	{
		free(start);
		exit(EXIT_SUCCESS);
	}
}

int		main(int ac, char **av)
{
	t_start	*start;

	if (!(start = malloc(sizeof(t_start))))
		return (0);
	start->list_a = NULL;
	start->list_b = NULL;
	ft_initialise(ac, av, &start);
	check_empty(start);
	ft_double(&start);
	ft_operate(start);
	ft_sorted(start);
	ft_exit_success(start);
}
