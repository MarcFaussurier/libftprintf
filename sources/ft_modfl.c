#include "libftprintf.h"

long double     ft_modfl(long double n, long double *int_part)
{
    long double     r;
    size_t          i;
    int             s;
    long double     k;
    long double     c;
    long double     e;

    if (n == 1)
    {
        *int_part = 1;
        return (0);
    }
    else if (n < 1)
    {
        *int_part = 0;
        return (n);
    }
    s = 0;
    k = n;
    while (k >= 1)
    {
        s += 1;
        k = k / ((long double)10);
    }
    i = 0;
    k = n;
    while (k >= 1 && s >= 0)
    {
        e = ft_pow(10, s);
        c = (char)  (k / (long double)e);
        k -= ((long double)c) * ((long double) e);
        s -= 1;
    }
    r = k;
    *int_part = n - r;
    return (r);
}
