#include "libftprintf.h"

char	    	*ft_vstrnew(unsigned int n, va_list ap)
{
    t_list      *lst;

    lst = ft_vlststrnew(n, ap);
    if (lst)
        return (ft_lststrjoin(lst));
    return (NULL);
}
