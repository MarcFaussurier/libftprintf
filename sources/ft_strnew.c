#include "libftprintf.h"

t_list                  *ft_lststrnew(unsigned int n, ...)
{
    t_list              *o;
    va_list             ap;
    unsigned short      k;
    char                *s;

    va_start(ap, n);
    o = NULL;
    k = 0;
    while ((s = va_arg(ap, char*)) && k++ < n)
        if (!ft_lststradd(&o, s))
        {
            ft_lstclear(&o, &free);
            return (NULL);
        }
    va_end(ap);
    return (o);
}
