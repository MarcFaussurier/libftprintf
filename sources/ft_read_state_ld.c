#include "libftprintf.h"

t_ld_state          ft_read_state_ld(long double x)
{
    t_long_double        *xp;

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


