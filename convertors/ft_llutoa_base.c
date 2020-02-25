#include "libftprintf.h"

char                        *ft_llutoa_base(const char *base, unsigned long long int n)
{
    unsigned short          n_len;
    unsigned short          i;
    size_t                  base_len;
    unsigned long long      n_bkp;
    char                    *output;
    
    n_bkp = n;
    n_len = 1;
    base_len = ft_strlen(base);
    while ((n_bkp /= base_len) && ++n_len)
        ;
    output = malloc(n_len + 1);
    n_bkp = n;
    i = 0;
    while (i < n_len)
    {
        output[n_len - i - 1] = base[n_bkp % base_len];
        n_bkp /= base_len;
        i += 1;
    }
    output[n_len] = '\0';
    return (output);
}
