#include <libftprintf.h>

char                *ft_ldtoa(long double n)
{

 /*   size_t          output_len;

    long double     n_bkp;
    char            d;
*/
    char            *output;

    (void) n;
    output = NULL;
    /*
    output_len = 1;
    n_bkp = n;
    if (n_bkp < 0)
    {
        output_len += 1;
        n_bkp = -n_bkp;
    }
    while (n_bkp >= 1)
    {
        output_len += 1;
        n_bkp /= 10;
    }
    if (n_bkp < 1)
    {
        output_len += 1;
        while (n_bkp != 0)
        {
            output_len += 1;
            d = n_bkp * 10;
            n = n - (d / 10) * 10;
        }
    }
    output = malloc(output_len + 1);
    n_bkp = n;
    if (n_bkp < 0)
    {

        output[output_len++] = '-';
        n_bkp = -n_bkp;
    }
    while (n_bkp >= 1)
    {
        output[output_len++] = '0' + (int) (n_bkp - (n_bkp / 10) * 10);
        n_bkp /= 10;
    }
    else if (n_bkp < 1)
    {
        output[output_len++] = '.';
        while (n_bkp != 0)
        {
            d = n_bkp * 10;
            output[output_len++] = '0' + d;
            n = n - (d / 10) * 10;
        }
    }
    output[output_len] = '\0';
    */
    return (output);

}
