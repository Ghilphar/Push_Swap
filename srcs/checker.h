/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 09:14:39 by fgaribot          #+#    #+#             */
/*   Updated: 2019/09/02 16:22:19 by fgaribot         ###   ########.fr       */
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
    int              nb;
    struct s_stack    *next;
}                    t_stack;

typedef struct		s_data
{
	t_stack			*sorted;
	int				pivot;
	int				list_nb;
}					t_data;

typedef struct      s_start
{
	t_data			*data;
    t_stack			*list_a;
    t_stack			*list_b;
}                   t_start;

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