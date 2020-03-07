#include "libftprintf.h"

char        *ft_fmt_b(t_specifier_state state, va_list ap)
{
    char    *output;
    char    *swp;
    size_t  size;

    if (!ft_strlen(state.qualifiers) || !ft_strncmp(state.qualifiers, "l", 2))
        size = 4;
    else if (!ft_strncmp(state.qualifiers, 
                "llllllllllllllllllllllllllllllllllllllllllllllllllllllllllll",
                ft_strlen(state.qualifiers)
                ))
        size = ft_strlen(state.qualifiers) + 4;
    else if (!ft_strncmp(state.qualifiers, "h", 2))
        size = 2;
    else
        size = 1;

    swp = ft_btoa(va_arg(ap, void*), size);
    output = ft_stoa(state, STRING, swp);
    free(swp);
    return (output);
}
