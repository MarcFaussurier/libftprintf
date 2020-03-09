#include "libftprintf.h"

char            *ft_fmt_p(t_specifier_state state, va_list ap)
{
	state.flags.sharp = 1;
	free(state.qualifiers);
	state.qualifiers = malloc(2);
	state.qualifiers[0] = 'l';
	state.qualifiers[1] = 0;
	return (ft_unumtoa(state, ap, ft_isupper(state.specifier) ? B16 : b16,
				(char[3]){'0',ft_isupper(state.specifier) ? 'X' : 'x', 0}));
}
