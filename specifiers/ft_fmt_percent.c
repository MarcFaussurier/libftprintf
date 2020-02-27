#include "libftprintf.h"

char            *ft_fmt_percent(t_specifier_state state, va_list ap)
{
    (void) ap;
    return (ft_stoa(state, (char[2]) {'%', '\0'}, FALSE, FALSE));
}
