/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:52:21 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/15 16:21:34 by fgaribot         ###   ########.fr       */
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

int		ft_count_list(t_stack *first_list)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = first_list;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		test_sorted(t_start *start)
{
	t_stack	*to_test;
	t_stack	*tester;

	to_test = start->list_a;
	while (to_test != NULL && to_test->next != NULL)
	{
		tester = to_test->next;
		if (to_test->nb > tester->nb)
			return(0);
		to_test = tester;
	}
	return (1);
}
