#include "libftprintf.h"

char        *ft_fmt_x(t_specifier_state state, va_list ap)
{
    char        *swp;
	char		*num;
	char		*out;
    char        *base;

	base = ft_isupper(state.specifier) ? B16 : b16;
    if (!(ft_strncmp(state.qualifiers, "ll", 3)))
		num = ft_llutoa_base(base, va_arg(ap, unsigned long long));
	else if (!(ft_strncmp(state.qualifiers, "l", 2)))
		num = ft_lutoa_base(base, va_arg(ap, unsigned long));
	else if (!ft_strlen(state.qualifiers))
		num = ft_utoa_base(base, va_arg(ap, unsigned int));
	else if (!(ft_strncmp(state.qualifiers, "h", 2)))
		num = ft_hutoa_base(base, va_arg(ap, unsigned int));
	else if (!(ft_strncmp(state.qualifiers, "hh", 3)))
		num = ft_hhutoa_base(base, va_arg(ap, unsigned int));
	else
		num = NULL;
	if (!num)
		return (NULL);
	if (state.flags.sharp)
    {
        if (ft_isupper(state.specifier))
            swp = ft_strjoin("0X", num);
        else
            swp = ft_strjoin("0x", num);
        free(num);
    }
    else
        swp = num;
    out = ft_stoa(state, swp, TRUE);
	free(swp);
	return (out);
}
