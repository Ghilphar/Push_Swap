#include "checker.h"

void     swap_a(t_start *start)
{
    t_list  *first;
    t_list  *second;

    if (start->list_a != NULL && (start->list_a)->next != NULL)
    {
        first = start->list_a;
        second = (start->list_a)->next;
        first->next = second->next;
        second->next = first;
        start->list_a = second;
    }
}

void    swap_b(t_start *start)
{
    t_list  *first;
    t_list  *second;

    if (start->list_b != NULL && (start->list_b)->next != NULL)
    {
        first = start->list_b;
        second = (start->list_b)->next;
        first->next = second->next;
        second->next = first;
        start->list_b = second;
    }
}

void    swap_s(t_start *start)
{
    swap_a(start);
    swap_b(start);
}


void    push_a(t_start *start)
{
    t_list  *to_push;

    if (start->list_b != NULL)
    {
        to_push = start->list_b;
        start->list_b = to_push->next;
        to_push->next = start->list_a;
        start->list_a = to_push;
    }
}

void    push_b(t_start *start)
{
    t_list  *to_push;

    if (start->list_a != NULL)
    {
        to_push = start->list_a;
        start->list_a = to_push->next;
        to_push->next = start->list_b;
        start->list_b = to_push;
    }
}

void    rotate_a(t_start *start)
{
    t_list  *last;
    t_list  *first;
    t_list  *second;

    first = start->list_a;
    second = first->next;
    last = first;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    start->list_a = second;
}

void    rotate_b(t_start *start)
{
    t_list  *last;
    t_list  *first;
    t_list  *second;

    first = start->list_b;
    second = first->next;
    last = first;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
    first->next = NULL;
    start->list_b = second;
}

void    rotate_r(t_start *start)
{
    rotate_a(start);
    rotate_b(start);
}

void    reverse_rotate_a(t_start *start)
{
    t_list  *last;
    t_list  *penultimate;

    last = start->list_a;
    penultimate = start->list_a;
    while ((penultimate->next)->next != NULL)
        penultimate = penultimate->next;
    while (last->next != NULL)
        last = last->next;
    penultimate->next = NULL;
    last->next = start->list_a;
    start->list_a = last;
}

void    reverse_rotate_b(t_start *start)
{
    t_list  *last;
    t_list  *penultimate;

    last = start->list_b;
    penultimate = start->list_b;
    while ((penultimate->next)->next != NULL)
        penultimate = penultimate->next;
    while (last->next != NULL)
        last = last->next;
    penultimate->next = NULL;
    last->next = start->list_b;
    start->list_b = last;
}

void    reverse_rotate_r(t_start *start)
{
    reverse_rotate_a(start);
    reverse_rotate_b(start);
}