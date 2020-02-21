#include <libftprintf.h>

/*
** todo: finish me with https://en.wikipedia.org/wiki/Extended_precision
**
*/
t_ld_state          ft_read_state_ld(long double x)
{
    t_longdouble        *xp;

    xp = (void*) &x;
    // exp is not null  
    if (xp->s_parts.exponent)
    {
        // all exp bits are 1
        if (xp->s_parts.exponent == POW2_15)
        {
        
        }
    }
    return (NORMAL);
}

