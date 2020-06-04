#include "libftprintf.h"

t_ld_state                  ft_read_state_ld(long double x)
{
    t_long_double           *xp;
    short int               i;

    xp = (void*) &x;
    i = (xp->s_parts.exponent << 1) + 1;
    if (!xp->s_parts.exponent)
	{
		if (xp->s_parts.u_fraction.value)
			return FP_SUBNORMAL;
		return FP_ZERO;
	}
    if (i == -1)
	{
		if (xp->s_parts.u_fraction.value)
            return FP_NAN;
        return FP_MINUS_INFINITY;
	}
    if (i == SHRT_MAX)
	{
		if (xp->s_parts.u_fraction.value)
            return FP_NAN;
        return FP_INFINITY;
	}
    return FP_NORMAL;
}


