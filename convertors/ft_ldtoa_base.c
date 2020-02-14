#include <libftprintf.h>

char            *ft_ldtoa_base(const char *b, long double n)
{
    size_t      output_len;
   // size_t      b_len;
    //char        *num;
    //char        *output;
    long double n_bkp;

    (void) b;
    output_len = 0;
    n_bkp = n;
    if (n_bkp < 0)
    {
        n_bkp = -n_bkp;
        output_len += 1;
    }
    while (n_bkp > 10)
    {
        output_len += 1;
        n_bkp /= 10;
    }
    if (n_bkp != 0)
    {
        output_len += 1;
        while (n_bkp != 0)
        {
            n_bkp *= 10;
        }
    }
    return (ft_strdup(""));
}
