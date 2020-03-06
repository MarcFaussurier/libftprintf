#include <libftprintf.h>

char            *ft_unumtoa(t_specifier_state state, va_list ap, const char *b, t_bool prefix)
{
	char		*num;
	char		*out;
    char        *swp;
    t_fmt_type  t;

    if (!ft_strncmp(state.qualifiers, "z", 1))
        num = ft_llutoa_base(b, va_arg(ap, unsigned long long));
	else if (!(ft_strncmp(state.qualifiers, "ll", 2)))
		num = ft_llutoa_base(b, va_arg(ap, unsigned long long));
	else if (!(ft_strncmp(state.qualifiers, "l", 2)))
		num = ft_lutoa_base(b, va_arg(ap, unsigned long));
	else if (!ft_strlen(state.qualifiers))
		num = ft_utoa_base(b, va_arg(ap, unsigned int));
	else if (!(ft_strncmp(state.qualifiers, "hh", 3)))
		num = ft_hhutoa_base(b, va_arg(ap, unsigned int));
	else if (!(ft_strncmp(state.qualifiers, "h", 2)))
		num = ft_hutoa_base(b, va_arg(ap, unsigned int));
    else
		num = ft_strdup("0");
	if (!num)
		return (NULL);
	t = NUMBER;
    if (prefix && state.flags.sharp)
    {
        t = PREFIXED_NUMBER;
        if (ft_isupper(state.specifier))
            swp = ft_strjoin("0X", num);
        else
            swp = ft_strjoin("0x", num);
        free(num);
    }
    else
        swp = num;
    out = ft_stoa(state, t, swp);
	free(swp);
	return (out);
}
