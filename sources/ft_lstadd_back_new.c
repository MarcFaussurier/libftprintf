#include <libftprintf.h>

t_bool              ft_lstadd_back_new(t_list **lst, void *p)
{
    t_list          *n;

    if (!(n = ft_lstnew(p)))
        return (FALSE);
    ft_lstadd_back(lst, n);
    return (TRUE);
}
