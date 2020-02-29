#include "libftprintf.h"

char		*ft_itoa_base(const char *base, int n)
{
    char    *o;

	o = (ft_llitoa_base(base, n));
    if (n == -101)
        printf("got 101 %s\n", o);
    return (o);
}
