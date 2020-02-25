#include <libftprintf.h>

t_bool              ft_lstadd_front_new(t_list **lst, void *p)
{
    t_list          *i;

    if (!(i = ft_lstnew(p)))
        return (FALSE);
    ft_lstadd_front(lst, i);
    return (TRUE);
}
