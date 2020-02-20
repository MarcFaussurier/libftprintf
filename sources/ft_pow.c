#include <libftprintf.h>

long double         ft_upow(long double n, unsigned short p)
{
    if (!p)
        return (1);
    if (p == 1)
        return (n);
    return (n * ft_pow(n, p - 1));
}

long double         ft_pow(long double n, short p)
{
    if (p < 0)
        return (1 / ft_upow(n, -p));
    return (n * ft_upow(n, p - 1));
}
