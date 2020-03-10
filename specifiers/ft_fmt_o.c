#include "libftprintf.h"

char        *ft_fmt_o(t_specifier_state state, va_list ap)
{
	if (state.flags.sharp && state.precision != NO_PRECISION && state.precision >= 1)
    {
        state.precision -= 1;
    }
    state.flags.plus = 0;
    state.flags.space = 0;
    return (ft_unumtoa(state, ap, b8, "0"));
}
