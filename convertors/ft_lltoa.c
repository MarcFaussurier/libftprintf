#include "libftprintf.h"

char                *ft_llitoa(long long int n)
{
    char            *swp;
    char            *output;

    if (n < 0)
    {
        swp = ft_llutoa(-n);
        output = ft_strjoin("-", swp);
        free(swp);
        return (output);
    }
    return (ft_llutoa(n));
}
