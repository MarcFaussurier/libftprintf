#include <libftprintf.h>

char                *ft_llutoa_base(const char *base, unsigned long long int n)
{
    char            *swp;
    char            *swp2;
    char            *output;
    unsigned long long int   
                    tmp;
    size_t          base_len;

    base_len = ft_strlen(base);
    if (n == 0)
        return (ft_strdup("0"));
    if (n < base_len)
        return ((char[2]) {base[n], '\0'});
    swp = (tmp = n / base_len) > 0 ? ft_llutoa_base(base, tmp) : "";
    swp2 = ft_llutoa_base(base, n % base_len);
    output = ft_strjoin(swp, swp2);
    free(swp);
    free(swp2);
    return (output);
}
