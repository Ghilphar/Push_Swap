/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 20:53:53 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/14 15:17:23 by fgaribot         ###   ########.fr       */
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

void	Operate_pa(t_start *start, int i)
{
	while (i-- > 0)
	{
		push_a(start);
		write(1,"pa\n", 3);
	}
}

void	Operate_pb(t_start *start, int i)
{
	while (i-- > 0)
	{
		push_b(start);
		write(1,"pb\n", 3);
	}
}

void	Operate_ra(t_start *start, int i)
{
	while (i-- > 0)
	{
		rotate_a(start);
		write(1, "ra\n", 3);
	}
}

void	Operate_rb(t_start *start, int i)
{
	while (i-- > 0)
	{
		rotate_b(start);
		write(1, "rb\n", 3);
	}
}

void	Operate_rr(t_start *start, int i)
{
	while (i-- > 0)
	{
		rotate_r(start);
		write(1, "rr\n", 3);
	}
}

void	Operate_rra(t_start *start, int i)
{
	while (i-- > 0)
	{
		reverse_rotate_a(start);
		write(1, "rra\n", 4);
	}
}

void	Operate_rrb(t_start *start, int i)
{
	while (i-- > 0)
	{
		reverse_rotate_b(start);
		write(1, "rrb\n", 4);
	}
}

void	Operate_rrr(t_start *start, int i)
{
	while (i-- > 0)
	{
		reverse_rotate_r(start);
		write(1, "rrr\n", 4);
	}
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

void	ft_reset_operations(t_nb_operations *nb_operations)
{
	nb_operations->ra = 0;
	nb_operations->rb = 0;
	nb_operations->rr = 0;
	nb_operations->rra = 0;
	nb_operations->rrb = 0;
	nb_operations->rrr = 0;
	nb_operations->total = 0;
}

void	little_list(t_start *start)
{
	write(1, "to_do\n", 6);
	return;
}

void	ft_underaction(t_start *start)
{
	start->data->nb_list_a = ft_count_list(start->list_a);
	if (start->data->nb_list_a <= 10)
	{
		little_list(start);
		exit(EXIT_SUCCESS);
	}
	if (!(start->operations_to_do = malloc(sizeof(t_nb_operations))))
		return;
	if (!(start->operations_tmp = malloc(sizeof(t_nb_operations))))
		return;
	ft_reset_operations(start->operations_to_do);
	ft_reset_operations(start->operations_tmp);
	Operate_pb(start, 2);
	//start->data->nb_list_a = ft_count_list(start->list_a);
	start->data->nb_list_b = ft_count_list(start->list_b);
}

void	merge_rr_rrr(t_start *start)
{
	if (start->operations_tmp->ra <= start->operations_tmp->rb)
	{
		start->operations_tmp->rr = start->operations_tmp->ra;
		start->operations_tmp->ra = 0;
		start->operations_tmp->rb = start->operations_tmp->rb - start->operations_tmp->rr;
	}
	else
	{
		start->operations_tmp->rr = start->operations_tmp->rb;
		start->operations_tmp->rb = 0;
		start->operations_tmp->ra = start->operations_tmp->ra - start->operations_tmp->rr;
	}
	if (start->operations_tmp->rra <= start->operations_tmp->rrb)
	{
		start->operations_tmp->rrr = start->operations_tmp->rra;
		start->operations_tmp->rra = 0;
		start->operations_tmp->rrb = start->operations_tmp->rrb - start->operations_tmp->rrr;
	}
	else
	{
		start->operations_tmp->rrr = start->operations_tmp->rrb;
		start->operations_tmp->rrb = 0;
		start->operations_tmp->rra = start->operations_tmp->rra - start->operations_tmp->rrr;
	}
}

void	total_operations(t_start *start)
{
	start->operations_tmp->total = start->operations_tmp->ra + start->operations_tmp->rb
	+ start->operations_tmp->rra + start->operations_tmp->rrb + start->operations_tmp->rr
	+ start->operations_tmp->rrr;
}

void	choose_ra_rb(t_start *start)
{
	start->operations_tmp->rra = 0;
	start->operations_tmp->rrb = 0;
	merge_rr_rrr(start);
	total_operations(start);
}

void	choose_rra_rrb(t_start *start)
{
	start->operations_tmp->ra = 0;
	start->operations_tmp->rb = 0;
	merge_rr_rrr(start);
	total_operations(start);
}

void	choose_ra_rrb(t_start *start)
{
	start->operations_tmp->rb = 0;
	start->operations_tmp->rra = 0;
	total_operations(start);
}

void	choose_rra_rb(t_start *start)
{
	start->operations_tmp->ra = 0;
	start->operations_tmp->rrb = 0;
	total_operations(start);
}

void	good_combination(t_start *start)
{
	int		ra_rb;
	int		rra_rrb;
	int		ra_rrb;
	int		rra_rb;

	if (start->operations_tmp->ra < start->operations_tmp->rb)
		ra_rb = start->operations_tmp->rb;
	else
		ra_rb = start->operations_tmp->ra;
	if (start->operations_tmp->rra < start->operations_tmp->rrb)
		rra_rrb = start->operations_tmp->rrb;
	else
		rra_rrb = start->operations_tmp->rra;
	ra_rrb = start->operations_tmp->ra + start->operations_tmp->rrb;
	rra_rb = start->operations_tmp->rra + start->operations_tmp->rb;
	if (ra_rb <= rra_rrb && ra_rb <= ra_rrb && ra_rb <= rra_rb)
		choose_ra_rb(start);
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
		choose_rra_rrb(start);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rrb && ra_rrb <= rra_rb)
		choose_ra_rrb(start);
	else if (rra_rb <= ra_rb && rra_rb <= rra_rrb && rra_rb <= ra_rrb)
		choose_rra_rb(start);
}

void	new_best(t_start *start)
{
	if (start->operations_tmp->total < start->operations_to_do->total)
	{
		free(start->operations_to_do);
		start->operations_to_do = start->operations_tmp;
		if (!(start->operations_tmp = malloc(sizeof(t_nb_operations))))
			return;
		ft_reset_operations(start->operations_tmp);
	}
	else if (start->data->first_total == 0)
	{
		start->data->first_total = 1;
		free(start->operations_to_do);
		start->operations_to_do = start->operations_tmp;
		if (!(start->operations_tmp = malloc(sizeof(t_nb_operations))))
			return;
		ft_reset_operations(start->operations_tmp);
	}
	else
		ft_reset_operations(start->operations_tmp);
}

void	ft_calcul_operations(int nb, int i, t_start *start)
{
	start->operations_tmp->ra = i - 1;
	start->operations_tmp->rra = start->data->nb_list_a - i + 1;
	if (start->operations_tmp->rra == start->data->nb_list_a)
		start->operations_tmp->rra = 0;
	start->operations_tmp->rb = start->data->place_on_b;
	start->operations_tmp->rrb = start->data->nb_list_b - start->data->place_on_b;
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

int		correct_place(t_start *start, int nb)
{
	int			i;
	t_stack		*tmp_1;
	t_stack		*tmp_2;
	t_stack		*last;

	i = 0;
	tmp_1 = start->list_b;
	tmp_2 = tmp_1->next;
	last = start->list_b;
	while (last->next != NULL)
		last = last->next;
	if ((nb < last->nb && nb < tmp_1->nb) && tmp_1->nb < last->nb && nb > start->data->min_list_b)
		return (0);
	if ((nb < tmp_1->nb && nb > last->nb && tmp_1->nb > last->nb) || (nb > tmp_1->nb && nb < last->nb && tmp_1->nb > last->nb))
		return (0);
	if ((nb > tmp_1->nb && nb < last->nb) && tmp_1->nb > last->nb && nb < start->data->max_list_b)
		return (0);
	if (nb > start->data->max_list_b)
	{
		while (tmp_1->nb != start->data->min_list_b)
		{
			i++;
			tmp_1 = tmp_1->next;
		}
	}
	else if (nb < start->data->min_list_b)
	{
		while (tmp_1->nb != start->data->min_list_b)
		{
			i++;
			tmp_1 = tmp_1->next;
		}
	}
	else
	{
		i++;
		while ((nb > tmp_1->nb && nb > tmp_2->nb) || (nb < tmp_1->nb && nb < tmp_2->nb) || (nb < tmp_1->nb && nb > tmp_2->nb))
		{
			i++;
			tmp_1 = tmp_1->next;
			tmp_2 = tmp_2->next;
		}
	}
	return (i);
}

void	list_extrema(t_start *start)
{
	t_stack		*tmp;

	tmp = start->list_b;
	start->data->max_list_b = tmp->nb;
	start->data->min_list_b = tmp->nb;
	while (tmp != NULL)
	{
		if (tmp->nb > start->data->max_list_b)
			start->data->max_list_b = tmp->nb;
		if (tmp->nb < start->data->min_list_b)
			start->data->min_list_b = tmp->nb;
		tmp = tmp->next;
	}
}

void	exec_operations(t_start *start)
{
	Operate_ra(start, start->operations_to_do->ra);
	Operate_rb(start, start->operations_to_do->rb);
	Operate_rr(start, start->operations_to_do->rr);
	Operate_rra(start, start->operations_to_do->rra);
	Operate_rrb(start, start->operations_to_do->rrb);
	Operate_rrr(start, start->operations_to_do->rrr);
	new_extrema(start->list_a->nb ,start);
	Operate_pb(start, 1);
	start->data->nb_list_a -= 1;
	start->data->nb_list_b += 1;
}

void	Rotate_b(t_start *start)
{
	t_stack *min;
	int		i;

	i = 0;
	min = start->list_b;
	while (min->nb != start->data->min_list_b)
	{
		i++;
		min = min->next;
	}
	if (start->data->nb_list_b < i && (i / start->data->nb_list_b) * 100 <= 50)
		Operate_rb(start, i);
	else
		Operate_rrb(start, start->data->nb_list_b - i);
}

void	Final_Push_a(t_start *start)
{
	Operate_pa(start, start->data->nb_list_b);
}

void	ft_algo(t_start *start)
{
	t_stack		*tmp;
	int			i;

	ft_underaction(start);
	tmp = start->list_a;
	list_extrema(start);
	while (tmp != NULL)
	{
		i = 0;
		start->data->first_total = 0;
		ft_reset_operations(start->operations_to_do);
		while (tmp != NULL)
		{
			i++;
			start->data->place_on_b = correct_place(start, tmp->nb);
			ft_calcul_operations(tmp->nb, i, start);
			tmp = tmp->next;
		}
		exec_operations(start);
		tmp = start->list_a;
	}
	Rotate_b(start);
	Final_Push_a(start);
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

int     main(int ac, char **av)
{
    t_start *start;
	t_stack *test;

    if (ac < 2)
        return(0);
    if (!(start = malloc(sizeof(t_start))))
        return(0);
    start->list_a = NULL;
    start->list_b = NULL;
	if (!(start->data = malloc(sizeof(t_data))))
		return(0);
    ft_initialise(ac, av, &start);
    ft_double(&start);
	if (test_sorted(start) == 1)
	{
		//CLEAR LEAKS BEFORE LEAVE;
		return (0);
	}
	ft_algo(start);
	Clear_leaks(start);
	return (0);
}