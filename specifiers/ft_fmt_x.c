#include "libftprintf.h"

char        *ft_fmt_x(t_specifier_state state, va_list ap)
{

	return (ft_unumtoa(state, ap, ft_isupper(state.specifier) ? B16 : b16,
				(char[3]){'0',ft_isupper(state.specifier) ? 'X' : 'x', 0}));
}
