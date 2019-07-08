#include "checker.h"

t_list  *swap(t_list *list)
{
    t_list  *first;
    t_list  *second;


    if (list != NULL && list->next != NULL)
    {
        first = list;
        second = first->next;
        first->next = second->next;
        second->next = first;
        return(second);
    }
    return(list);
}

t_start  *push_a(t_start *start)
{
    t_list  *to_push;

    if (start->list_b != NULL)
    {
        to_push = start->list_b;
        start->list_b = to_push->next;
        to_push->next = start->list_a;
        start->list_a = to_push;
    }
    return (start);
}

t_start *push_b(t_start *start)
{
    t_list  *to_push;

    if (start->list_a != NULL)
    {
        to_push = start->list_a;
        start->list_a = to_push->next;
        to_push->next = start->list_b;
        start->list_b = to_push;
    }
    return (start);
}