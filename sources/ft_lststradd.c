#include <libftprintf.h>

t_bool          ft_lststradd(t_list **str, char *ptr)
{

    t_list          *new;

    if (!ptr)
    {
        ft_lstclear(str, &free);
        return (FALSE);
    }
    if (!(new = ft_lstnew(ptr)))
    {
        free(ptr);
        ft_lstclear(str, &free);
        return (FALSE);
    }
    ft_lstadd_back(str, new);
    return (TRUE);
}
