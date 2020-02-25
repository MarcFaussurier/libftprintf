#include "libftprintf.h"

char                        *ft_llitoa_base(const char *base, long long int n)
{
    char                    *swp;
    char                    *output;

    if (n < 0)
    {
        swp = ft_llutoa_base(base, n);
        output = ft_strjoin("-", swp);
        free(swp);
        return (output);
    }
    else
        return (ft_llutoa_base(base, n));
}
