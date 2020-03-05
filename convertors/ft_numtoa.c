#include <libftprintf.h>

char            *ft_numtoa(t_specifier_state state, va_list ap, const char *b, t_bool prefix)
{
	char		*num;
	char		*out;
    char        *swp;

	if (!(ft_strncmp(state.qualifiers, "ll", 2)))
		num = ft_llitoa_base(b, va_arg(ap, long long));
	else if (!(ft_strncmp(state.qualifiers, "l", 2)))
		num = ft_litoa_base(b, va_arg(ap, long));
	else if (!ft_strlen(state.qualifiers))
		num = ft_itoa_base(b, va_arg(ap, int));
	else if (!(ft_strncmp(state.qualifiers, "hh", 3)))
		num = ft_hhitoa_base(b, va_arg(ap, int));
	else if (!(ft_strncmp(state.qualifiers, "h", 2)))
		num = ft_hitoa_base(b, va_arg(ap, int));
    else
		num = ft_strdup("-1");
	if (!num)
		return (NULL);
	if (prefix && state.flags.sharp)
    {
        if (ft_isupper(state.specifier))
            swp = ft_strjoin("0X", num);
        else
            swp = ft_strjoin("0x", num);
        free(num);
    }
    else
        swp = num;
    out = ft_stoa((t_stoa_args){state, swp, TRUE, FALSE, FALSE});
	free(swp);
	return (out);
}
