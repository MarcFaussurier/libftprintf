#include "libftprintf.h"

char            *ft_fmt_p(t_specifier_state state, va_list ap)
{
	state.flags.sharp = 1;
	free(state.qualifiers);
	state.qualifiers = "l";
    state.force_prefix = TRUE;
    return (ft_unumtoa(state, ap, b16, "0x"));
}
