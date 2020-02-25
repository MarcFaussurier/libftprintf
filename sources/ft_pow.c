#include "libftprintf.h"

long double         ft_pow(long double x, short n)
{
    long double     y;

    if (n < 0L)
    {
        x = 1 / x;
        n *= -1;
    }
    if (n == 0L)
        return (1L);
    y = 1L;
    while (n > 1)
    {
        if (!(n % 2))
        {
            x *= x;
            n /= 2;
        }
        else
        {
            y *= x;
            x *= x;
            n = (n - 1) / 2;
        }
    }
    return (x * y);
}
