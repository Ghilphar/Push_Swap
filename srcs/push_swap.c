/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:53:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/08/11 21:19:38 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    ft_algo(t_start **start)
{
    
}

int     main(int ac, char **av)
{
    t_start *start;

    if (ac < 2)
        return(0);
    if (!(start = malloc(sizeof(t_start))))
        return(0);
    start->list_a = NULL;
    start->list_b = NULL;
    ft_initialise(ac, av, &start);
    ft_double(&start);
    ft_algo(&start);
}