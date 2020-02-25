#include "libftprintf.h"

char        *ft_fmt_g(t_specifier_state state, va_list ap)
{
    (void) state;
    (void) ap;
    return (ft_strdup(""));
}
