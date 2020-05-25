#include "libftprintf.h"

char            *ft_ldtoa(long double n)
{
    long double i;
    long double r;

    return (ft_modld_toa(n, &i, &r, b10));
}
