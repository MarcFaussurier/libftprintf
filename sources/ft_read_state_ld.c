#include "libftprintf.h"

t_ld_state          ft_read_state_ld(long double x)
{
    t_long_double           *xp;
    unsigned char           a = 1;
    unsigned short          b = 1;
    unsigned                c = 1;
    unsigned long           d = 1;
    unsigned long long      e = 1;
    size_t                  f = 1;

    xp = (void*) &x;
    if (xp->s_parts.exponent)
    {
        if (xp->s_parts.exponent == POW2_15)
        {
            if (xp->s_parts.u_fraction.s_bb.i)
            {
                if (xp->s_parts.u_fraction.s_bb.y)
                {
                    if (xp->s_parts.u_fraction.s_bb.value)
                    {
                        return (QUIET_NOT_A_NUMBER);
                    }
                    return (QUIET_NOT_A_NUMBER_INVALID_OP);
                }
                if (xp->s_parts.u_fraction.s_bb.value)
                    return (NOT_A_NUMBER);
                return (INFINITY);
            }
            if (xp->s_parts.u_fraction.s_bb.y)
                return (INVALID_OP);
            if (xp->s_parts.u_fraction.s_bb.value)
                return (INVALID_OP);
            return (INVALID_OP);

        }
        ft_printf("a: %hhb\n", &a);
        ft_printf("b: %hb\n", &b);
        ft_printf("c: %b\n", &c);
        ft_printf("d: %lb\n", &d);
        ft_printf("e: %llb\n", &e);
        ft_printf("f: %zb\n", &f);
        x = 1;
        ft_printf("x: %#b\n", sizeof(long double), &x);
        if (xp->s_parts.u_fraction.s_bb.i)
            return (NORMAL);
        return (INVALID_OP);
    }
    if (xp->s_parts.u_fraction.s_bb.i)
        return (CANT_BE_GEN);
    if (xp->s_parts.u_fraction.s_bb.value)
        return(DENORMAL);
    return (ZERO);
}


