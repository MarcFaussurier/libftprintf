#include <libftprintf.h>

long double             ft_modfl(long double x, long double *i)
{
    int                                     e;
    unsigned long                           r;
    t_longdouble                            *xp;
    t_longdouble                            *ip;

    xp = (void*)&x;
    ip = (void*)i;
    e = xp->s_value.exponent - LDEXPBIAS;
    if (e < 32)
    {
        if (e < 0)
        {
            ip->value = 0;
            xp->s_value.sign = ip->s_value.sign;
            return (x);
        }
        else
        {
            r = ((unsigned long) ULONG_MAX) >> (e + 1);
            if (!xp->s_value.s_mantissa_parts.low && !(xp->s_value.s_mantissa_parts.low & r))
            {
                ip->value = x;
                x = 0;
                ip->s_value.sign = xp->s_value.sign;
                return (x);
            }
            ip->s_value.sign = xp->s_value.sign;
            ip->s_value.exponent = ip->s_value.exponent;
            ip->s_value.s_mantissa_parts.high = xp->s_value.s_mantissa_parts.high & ~ r;
            ip->s_value.s_mantissa_parts.low = 0;
            return (x - *i);
        }
    }
    else if (e > 63)
    {
        *i = x;
        if (ft_isnanl(x) || ft_isinfl(x))
            return (x);
        x = 0;
        xp->s_value.sign = ip->s_value.sign;
        return (x);
    }
    r = (unsigned long) ULONG_MAX >> (e - 32);
    if (!xp->s_value.s_mantissa_parts.low)
    {
        *i = x;
        x = 0;
        xp->s_value.sign = ip->s_value.sign;
        return (x);
    }
    ip->s_value.sign = xp->s_value.sign;
    ip->s_value.exponent = xp->s_value.exponent;
    ip->s_value.s_mantissa_parts.high = xp->s_value.s_mantissa_parts.high;
    ip->s_value.s_mantissa_parts.low = xp->s_value.s_mantissa_parts.low & ~r;
    return (x - *i);
}
