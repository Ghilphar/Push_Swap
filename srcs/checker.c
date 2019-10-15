/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:33 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 17:12:37 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_start	*start;

	if (!(start = malloc(sizeof(t_start))))
		return (0);
	start->list_a = NULL;
	start->list_b = NULL;
	if (ac <= 2)
		ft_exit_success(start);
	ft_initialise(ac, av, &start);
	ft_double(&start);
	ft_operate(start);
	ft_sorted(start);
	ft_exit_success(start);
}
