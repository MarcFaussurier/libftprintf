#include "libftprintf.h"

char            *ft_ldtoa(long double n)
{
    long double i;
    long double r;

    if (ft_isnanl(n))
        return (ft_strdup("nan"));
    else if (ft_isinfl(n))
    {
        if (n > 0)
            return (ft_strdup("inf"));
        return (ft_strdup("-inf"));
    }
    return (ft_modld_toa(n, &i, &r, b10));
}
