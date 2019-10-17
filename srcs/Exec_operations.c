/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:05:05 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/17 13:44:57 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_operations(t_start *start)
{
	operate_ra(start, start->operations_to_do->ra);
	operate_rb(start, start->operations_to_do->rb);
	operate_rr(start, start->operations_to_do->rr);
	operate_rra(start, start->operations_to_do->rra);
	operate_rrb(start, start->operations_to_do->rrb);
	operate_rrr(start, start->operations_to_do->rrr);
	new_extrema(start->list_a->nb, start);
	operate_pb(start, 1);
	start->data->nb_list_a -= 1;
	start->data->nb_list_b += 1;
}

void	ft_underaction(t_start *start)
{
	start->data->nb_list_a = ft_count_list(start->list_a);
	if (start->data->nb_list_a == 3 || start->data->nb_list_a == 5)
	{
		little_list(start);
		exit(EXIT_SUCCESS);
	}
	if (!(start->operations_to_do = malloc(sizeof(t_nb_operations))))
		return ;
	if (!(start->operations_tmp = malloc(sizeof(t_nb_operations))))
		return ;
	ft_reset_operations(start->operations_to_do);
	ft_reset_operations(start->operations_tmp);
	operate_pb(start, 2);
	start->data->nb_list_b = ft_count_list(start->list_b);
	list_extrema_b(start);
}

void	new_best(t_start *start)
{
	if (start->operations_tmp->total < start->operations_to_do->total)
	{
		free(start->operations_to_do);
		start->operations_to_do = start->operations_tmp;
		if (!(start->operations_tmp = malloc(sizeof(t_nb_operations))))
			return ;
		ft_reset_operations(start->operations_tmp);
	}
	else if (start->data->first_total == 0)
	{
		start->data->first_total = 1;
		free(start->operations_to_do);
		start->operations_to_do = start->operations_tmp;
		if (!(start->operations_tmp = malloc(sizeof(t_nb_operations))))
			return ;
		ft_reset_operations(start->operations_tmp);
	}
	else
		ft_reset_operations(start->operations_tmp);
}

void	ft_calcul_operations(int i, t_start *start)
{
	start->operations_tmp->ra = i - 1;
	start->operations_tmp->rra = start->data->nb_list_a - i + 1;
	if (start->operations_tmp->rra == start->data->nb_list_a)
		start->operations_tmp->rra = 0;
	start->operations_tmp->rb = start->data->place_on_b;
	start->operations_tmp->rrb = start->data->nb_list_b -
	start->data->place_on_b;
	if (start->data->place_on_b == start->data->nb_list_b)
		start->operations_tmp->rrb = 1;
	good_combination(start);
	new_best(start);
}

void	new_extrema(int nb, t_start *start)
{
	if (nb < start->data->min_list_b)
		start->data->min_list_b = nb;
	if (nb > start->data->max_list_b)
		start->data->max_list_b = nb;
}
