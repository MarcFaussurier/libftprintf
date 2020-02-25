#include "libftprintf.h"

void            ft_putmem(char *s, size_t n)
{
    size_t      i;

    i = 0;
    while (i < n)
    {
        ft_putchar(s[i]);
        i += 1;
    }
    return ;
}
