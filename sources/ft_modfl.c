#include <libftprintf.h>

long double             ft_modfl(long double x, long double *i)
{
    int                                     e;
    unsigned int                            r;
    t_long_double                           *xp;
    t_long_double                           *ip;

    xp = (void*)&x;
    ip = (void*)i;
    printf("sign: %i\n", xp->bytes[9] << 8);
    printf("e: %i bias: %i \n", xp->s_parts.exponent, LDEXPBIAS);
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
        r = UINT_MAX >> (e + 1);
        if (!xp->s_parts.u_mantisa.s_pair.low && !(xp->s_parts.u_mantisa.s_pair.low & r))
        {
            *i = x;
            x = 0;
            ip->s_parts.sign = xp->s_parts.sign;
            return (x);
        }
        ip->s_parts.sign = xp->s_parts.sign;
        ip->s_parts.exponent = xp->s_parts.exponent;
        ip->s_parts.u_mantisa.s_pair.high = xp->s_parts.u_mantisa.s_pair.high &~r;
        ip->s_parts.u_mantisa.s_pair.low = 0;
        return (x - *i);
    }
    if (e > 63)
    {
        *i = x;
        if (ft_isnanl(x) || ft_isinfl(x))
            return (x);
        x = 0;
        xp->s_parts.sign = ip->s_parts.sign;
        return (x);
    }
    r = ULONG_MAX >> (e - 32);
    if (!xp->s_parts.u_mantisa.s_pair.low)
    {
        *i = x;
        x = 0;
        xp->s_parts.sign = ip->s_parts.sign;
        return (x);
    }
    ip->s_parts.sign = xp->s_parts.sign;
    ip->s_parts.exponent = xp->s_parts.exponent;
    ip->s_parts.u_mantisa.s_pair.high = xp->s_parts.u_mantisa.s_pair.high;
    ip->s_parts.u_mantisa.s_pair.low = xp->s_parts.u_mantisa.s_pair.low & ~r;
    return (x - *i);
}
