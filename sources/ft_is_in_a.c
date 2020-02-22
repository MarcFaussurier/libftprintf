#include <libftprintf.h>

t_bool              ft_is_in_a(int i, int* p, unsigned int k)
{
    size_t          x;


    x = 0;
    while (x < k)
        if (i == p[x++])
            return (TRUE);
    return (FALSE);
}
