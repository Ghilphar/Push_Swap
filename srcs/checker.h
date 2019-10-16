/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:39 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/16 20:30:12 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** LIBRAIRIES
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

/*
** STRUCTURES
*/

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_data
{
	int				place_on_b;
	int				max_list_a;
	int				min_list_a;
	int				max_list_b;
	int				min_list_b;
	int				nb_list_a;
	int				nb_list_b;
	int				first_total;
}					t_data;

typedef struct		s_nb_operations
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	int				total;
}					t_nb_operations;

typedef struct		s_start
{
	t_nb_operations	*operations_to_do;
	t_nb_operations	*operations_tmp;
	t_data			*data;
	t_stack			*list_a;
	t_stack			*list_b;
}					t_start;

/*
** TESTS
*/

void				ft_double(t_start **start);
void				ft_sorted(t_start *start);

/*
** EXITS
*/

void				ft_exit_success(t_start *start);
void				ft_exit_failure(t_start *start);
void				ft_exit_error(t_start *start);

/*
** PARSING
*/

t_stack				*ft_new(int nb);
void				ft_initialise(int ac, char **av, t_start **start);
void				ft_add(t_start **start, char *num);
void				ft_operate(t_start *start);

/*
** OPERATIONS
*/

//typedef				void (*Operations_t)(t_start *start);

void				ft_swaps(char *line, t_start *start);

void				swap_a(t_start *start);
void				swap_b(t_start *start);
void				swap_s(t_start *start);

void				ft_pushs(char *line, t_start *start);

void				push_a(t_start *start);
void				push_b(t_start *start);

void				ft_rotates(char *line, t_start *start);

void				rotate_a(t_start *start);
void				rotate_b(t_start *start);
void				rotate_r(t_start *start);

void				ft_reverse_rotates(char *line, t_start *start);

void				reverse_rotate_a(t_start *start);
void				reverse_rotate_b(t_start *start);
void				reverse_rotate_r(t_start *start);

/*
** ---------------------Push_Swap
*/

/*
**	Clear_Leaks_PS
*/

void				clear_leaks(t_start *start);
void				clear_leaks_2(t_start *start);

/*
**	Best_combination
*/

void				choose_ra_rb(t_start *start);
void				choose_rra_rrb(t_start *start);
void				choose_ra_rrb(t_start *start);
void				choose_rra_rb(t_start *start);
void				good_combination(t_start *start);

/*
**	Correct_Place_on_b
*/

int					nb_sup_max(t_start *start);
int					nb_inf_min(t_start *start);
int					nb_inf_max_sup_min(t_start *start, int nb);
int					place_on_b(t_start *start, int nb);

/*
**	Correct_Place
*/

int					correct_place(t_start *start, int nb);
int					possibli_first_place(t_start *start, int nb);
void				ft_algo(t_start *start);

/*
**	Exec_operations
*/

void				exec_operations(t_start *start);
void				ft_underaction(t_start *start);
void				new_best(t_start *start);
void				ft_calcul_operations(int i, t_start *start);
void				new_extrema(int nb, t_start *start);

/*
**	Extrema_PS
*/

void				list_extrema_b(t_start *start);
void				list_extrema_a(t_start *start);

/*
**	List_3
*/

void				rotate_max_bottom(t_start *start);
void				rotate_min_top(t_start *start);
void				list_3(t_start *start);

/*
**	List_5
*/

void				max_to_list_b(t_start *start);
void				min_to_list_b(t_start *start);
void				list_5(t_start *start);
void				little_list(t_start *start);

/*
**	Merge_total_operations
*/

void				merge_rr(t_start *start);
void				merge_rr_rrr(t_start *start);
void				total_operations(t_start *start);
void				ft_reset_operations(t_nb_operations *nb_operations);

/*
**	Operate_push_sa
*/

void				operate_sa(t_start *start);
void				operate_pa(t_start *start, int i);
void				operate_pb(t_start *start, int i);
void				final_push_a(t_start *start);

/*
**	Operate_reverse_rotates
*/

void				operate_rra(t_start *start, int i);
void				operate_rrb(t_start *start, int i);
void				operate_rrr(t_start *start, int i);

/*
**	Operate_rotates
*/

void				operate_ra(t_start *start, int i);
void				operate_rb(t_start *start, int i);
void				operate_rr(t_start *start, int i);
void				rotate_final_b(t_start *start);

/*
**	Print_lists
*/

void				print_list_a(t_start *start);
void				print_list_b(t_start *start);
void				print_lists(t_start *start);
int					ft_count_list(t_stack *first_list);
int					test_sorted(t_start *start);

#endif
