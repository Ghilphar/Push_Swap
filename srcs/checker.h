/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:39 by fgaribot          #+#    #+#             */
/*   Updated: 2019/10/10 20:02:21 by fgaribot         ###   ########.fr       */
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

typedef struct       s_stack
{
    int             nb;
    struct s_stack  *next; // (struct s_stack = t_stack)
}                   t_stack;

typedef struct		s_data
{
	t_stack			*sorted;
	int				place_on_b;
	int				max_list_b;
	int				min_list_b;
	int				nb_list_a;
	int				nb_list_b;
	int				first_total;
}					t_data;

typedef struct      s_start
{
	t_nb_operations *operations_to_do;
	t_nb_operations *operations_tmp;
	t_data			*data;
    t_stack			*list_a;
    t_stack			*list_b;
}                   t_start;

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


/*
** TESTS
*/

void	ft_double(t_start **start);
void	ft_sorted(t_start *start);

/*
** EXITS
*/

void	ft_exit_success(t_start *start);
void    ft_exit_failure(t_start *start);
void	ft_exit_error(t_start *start);

/*
** PARSING
*/

t_stack	*ft_new(int nb);
void	ft_initialise(int ac, char **av, t_start **start);
void	ft_add(t_start **start, char *num);
void	ft_Operate(t_start *start);

/*
** OPERATIONS
*/

typedef		void (*Operations_t)(t_start *start);

void		ft_swaps(char *line, t_start *start);

void        swap_a(t_start *start);
void        swap_b(t_start *start);
void        swap_s(t_start *start);

void		ft_pushs(char *line, t_start *start);

void        push_a(t_start *start);
void        push_b(t_start *start);

void		ft_rotates(char *line, t_start *start);

void        rotate_a(t_start *start);
void        rotate_b(t_start *start);
void        rotate_r(t_start *start);

void		ft_reverse_rotates(char *line, t_start *start);

void        reverse_rotate_a(t_start *start);
void        reverse_rotate_b(t_start *start);
void        reverse_rotate_r(t_start *start);

#endif