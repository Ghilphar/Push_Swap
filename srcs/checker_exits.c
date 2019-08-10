/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:27 by fgaribot          #+#    #+#             */
/*   Updated: 2019/08/10 09:15:47 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_exit_success(t_start *start)
{
	t_stack		*tmp;

	tmp = start->list_a;
	while (tmp != NULL)
	{
		tmp->nb = 0;
		free(tmp);
		tmp = tmp->next;
	}
	tmp = start->list_b;
	while (tmp != NULL)
	{
		tmp->nb = 0;
		free(tmp);
		tmp = tmp->next;
	}
	start->list_a = NULL;
	start->list_b = NULL;
	free(start);
	printf("OK\n");
	exit(EXIT_SUCCESS);
}

void	ft_exit_failure(t_start *start)
{
	t_stack		*tmp;

	tmp = start->list_a;
	while (tmp != NULL)
	{
		tmp->nb = 0;
		free(tmp);
		tmp = tmp->next;
	}
	tmp = start->list_b;
	while (tmp != NULL)
	{
		tmp->nb = 0;
		free(tmp);
		tmp = tmp->next;
	}
	start->list_a = NULL;
	start->list_b = NULL;
	free(start);
	printf("KO\n");
	exit(EXIT_FAILURE);
}

void	ft_exit_error(t_start *start)
{
	t_stack		*tmp;

	tmp = start->list_a;
	while (tmp != NULL)
	{
		tmp->nb = 0;
		free(tmp);
		tmp = tmp->next;
	}
	tmp = start->list_b;
	while (tmp != NULL)
	{
		tmp->nb = 0;
		free(tmp);
		tmp = tmp->next;
	}
	start->list_a = NULL;
	start->list_b = NULL;
	free(start);
	write(2,"Error\n", 6);
	exit(EXIT_FAILURE);
}
