#include <libftprintf.h>

long double             ft_modfl(long double x, long double *i)
{
    int                                     e;
    unsigned long                           r;
    t_longdouble                            *xp;
    t_longdouble                            *ip;

    ft_putstr("b");
    xp = (void*)&x;
    ip = (void*)i;
    e = xp->s_parts.exponent - LDEXPBIAS;
    if (e < 32)
    {
        ft_putstr("<32");
        if (e < 0)
        {
            *i = 0;
            xp->s_parts.sign = ip->s_parts.sign;
            return (x);
        }
        r = ((unsigned long) ULONG_MAX) >> (e + 1);
        if (!xp->s_parts.s_mantissa_p.low && !(xp->s_parts.s_mantissa_p.low & r))
        {
            ft_putstr ("hi\ni");
            *i = x;
            x = 0;
            ip->s_parts.sign = xp->s_parts.sign;
            return (x);
        }
        ip->s_parts.sign = xp->s_parts.sign;
        ip->s_parts.exponent = ip->s_parts.exponent;
        ip->s_parts.s_mantissa_p.high = xp->s_parts.s_mantissa_p.high & ~ r;
        ip->s_parts.s_mantissa_p.low = 0;
        return (x - *i);
    }
    if (e > 63)
    {
        ft_putstr(">63");
        printf("e: %i\n", e);
        *i = x;
        if (ft_isnanl(x) || ft_isinfl(x))
        {
            ft_putstr("inf or nan\n");
            return (x);
        }
        x = 0;
        xp->s_parts.sign = ip->s_parts.sign;
        return (x);
    }
    r = (unsigned long) ULONG_MAX >> (e - 32);
    if (!xp->s_parts.s_mantissa_p.low)
    {
        ft_putstr("no mantissa low");
        *i = x;
        x = 0;
        xp->s_parts.sign = ip->s_parts.sign;
        return (x);
    }
    ip->s_parts.sign = xp->s_parts.sign;
    ip->s_parts.exponent = xp->s_parts.exponent;
    ip->s_parts.s_mantissa_p.high = xp->s_parts.s_mantissa_p.high;
    ip->s_parts.s_mantissa_p.low = xp->s_parts.s_mantissa_p.low & ~r;
    ft_putstr("end");
    return (x - *i);
}
