#include <libftprintf.h>

char                *ft_llitoa(long long int n)
{
    char            *swp;
    char            *swp2;
    char            *output;
    long long int   tmp;

    if (n == 0)
        return (ft_strdup("0"));
    if (n < 0)
    {
        swp = ft_llitoa(-n);
        output = ft_strjoin("-", swp);
        free(swp);
        return (output);
    }
    if (n < 10)
        return ((char[2]) {n + '0', '\0'});
    swp = (tmp = n / 10) > 0 ? ft_llitoa(tmp) : "";
    swp2 = ft_llitoa(n % 10);
    output = ft_strjoin(swp, swp2);
    free(swp);
    free(swp2);
    return (output);
}
