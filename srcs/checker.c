#include "checker.h"

t_list  *ft_lstnew(int nb)
{
    t_list   *new;

    if (!(new = malloc(sizeof(t_list))))
        return(NULL);
    new->nb = nb;
    new->next = NULL;
    return (new);
}

void    ft_lstaddend(t_list **alist, t_list *new)
{
    t_list      *tmp;

    tmp = *alist;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}


int main()
{
    int i;
    t_list  *tmp;
    t_list  *mylist;

    i = -1;
    mylist = ft_lstnew(-1);
    while (i++ < 10)
    {

        tmp = ft_lstnew(i); 
        ft_lstaddend(&mylist, tmp);
    }
    mylist = swap(mylist);
    while (mylist != NULL)
    {
        printf("count : %d", mylist->nb);
        mylist = mylist->next;
    }
    return(0);
}
