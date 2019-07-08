#ifndef CHECKER_H
# define CHECKER_H

/*
** LIBRAIRIES
*/

# include <stdlib.h>
# include <stdio.h>

/*
** STRUCTURES
*/

typedef struct       s_list
{
    int              nb;
    struct s_list    *next;
}                    t_list;

typedef struct      s_start
{
    t_list          *list_a;
    t_list          *list_b;
}                   t_start;


/*
** OPERATIONS
*/

t_list      *swap(t_list *list);
t_start     *push_b(t_start *start);
t_start     *push_b(t_start *start);

#endif