#ifndef CHECKER_H
# define CHECKER_H

/*
** LIBRAIRIES
*/

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

typedef struct      s_start
{
    t_stack          *list_a;
    t_stack          *list_b;
}                   t_start;


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