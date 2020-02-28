#include "libftprintf.h"

char                *ft_wstrtoa(wchar_t *str)
{
    char            *o;
    size_t          o_len;
    size_t          i;
    unsigned char   y;

    o_len = 1;
    i = 0;
    while (str[i])
    {
        y = 0;
        while (y < 4)
        {
            if (((t_wchar*)str)->bytes[y])
                o_len += 1;
            y += 1;
        }
        i += 1;
    }
    o = malloc(o_len);
    i = 0;
    while (*str)
    {
        y = 0;
        while (y < 4)
        {
            if (((t_wchar*)str)->bytes[y])
                o[i++] = ((t_wchar*)str)->bytes[y];
            y += 1;
        }
        str += 1;
    }
    o[i] = '\0';
    return (o);
}
