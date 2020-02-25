#include "libftprintf.h"

void                ft_lstdel_node(t_list **lst, t_list *itm, void(* del)(void*))
{
    t_list          *current;
    t_list          *swp;
    t_list          *prev;

    if (*lst == itm)
    {
        swp = itm->next;
        ft_lstdelone(*lst, del);
        *lst = swp;
        return;
    }
    current = (*lst)->next;
    prev = *lst;
    while (current)
    {
        if (current == itm)
        {
            swp = current;
            ft_lstdelone(*lst, del);
            prev->next = swp;
            return;
        }
        prev = current;
        current = current->next;
    }
    return;
}
