#include "libftprintf.h"

char            *ft_fmt_p(t_specifier_state state, va_list ap)
{
    char        *output;
    char        *swp;
    char        *swp2;

    (void) state;
	swp = ft_llutoa_base(b16, (unsigned long long) va_arg(ap, void *));
    swp2 = ft_strjoin("0x", swp);
    free(swp);
    output = ft_stoa(state, PREFIXED_NUMBER, swp2);
    free(swp2);
    
    return (output);
}
