#include "libftprintf.h"

t_ld_state                  ft_read_state_ld(long double x)
{
    t_long_double           *xp;

    xp = (void*) &x;
	if (!xp->s_parts.exponent)
	{
		if (xp->s_parts.u_fraction.value)
			return FP_SUBNORMAL;
		return FP_ZERO;
	}
    if (((xp->s_parts.exponent << 2) + 3)  == USHRT_MAX)
	{
		if (xp->s_parts.u_fraction.value)
            return FP_NAN;
        return FP_INFINITE;
	}
	return FP_NORMAL;
}


