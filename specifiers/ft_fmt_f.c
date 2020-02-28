#include "libftprintf.h"

char        *ft_fmt_f(t_specifier_state state, va_list ap)
{
    char    *num;
    char    *out;

    if (!ft_strlen(state.qualifiers))
        num = ft_ftoa((float) va_arg(ap, double));
    else if (!ft_strncmp(state.qualifiers, "l", 2))
        num = ft_dtoa(va_arg(ap, double));
    else if (!ft_strncmp(state.qualifiers, "L", 2))
        num = ft_ldtoa(va_arg(ap, long double));
    else
        num = NULL;
    if (!num)
        return (NULL);
    if (state.precision == NO_PRECISION)
    {
       	state.precision = 6 + ft_strchr(num, '.') - num + 1;
    }
    out = ft_stoa(state, num, FALSE, FALSE);
    free(num);
    return (out);
}
