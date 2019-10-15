/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:52:21 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 11:55:04 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_list_a(t_start *start)
{
	t_stack *test;

	printf("|\n");
	test = start->list_a;
	while (test != NULL)
	{
		printf("%d\n", test->nb);
		test = test->next;
	}
	printf("|\n");
}

void	print_list_b(t_start *start)
{
	t_stack *test;

	printf("|\n");
	test = start->list_b;
	while (test != NULL)
	{
		printf("%d\n", test->nb);
		test = test->next;
	}
	printf("|\n");
}

void	print_lists(t_start *start)
{
	print_list_a(start);
	print_list_b(start);
}