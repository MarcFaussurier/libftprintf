#include "libftprintf.h"

char        *ft_fmt_o(t_specifier_state state, va_list ap)
{
    return (ft_unumtoa(state, ap, b8, TRUE));
}
