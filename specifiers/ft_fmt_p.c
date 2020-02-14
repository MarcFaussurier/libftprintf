#include <libftprintf.h>

char            *ft_fmt_p(t_specifier_state state, va_list ap)
{
    char        *output;
    char        *swp;

    (void) state;
    swp = ft_llutoa_base(b16, (unsigned long long) va_arg(ap, void *));
    output = ft_strjoin("0x", swp);
    free(swp);
    return (output);
}
