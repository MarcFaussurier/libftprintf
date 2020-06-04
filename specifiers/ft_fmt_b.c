#include "libftprintf.h"

char        *ft_fmt_b(t_specifier_state state, va_list ap)
{
    char    *output;
    char    *swp;
    size_t  size;
    void    *arg;

    if (state.flags.sharp)
        size = va_arg(ap, size_t);
    else if (!ft_strlen(state.qualifiers))
        size = sizeof(int);
    else if (!ft_strncmp(state.qualifiers, zz, ft_strlen(state.qualifiers)))
        size = sizeof(size_t);
    else if (!ft_strncmp(state.qualifiers, "ll", 2) || !ft_strncmp(state.qualifiers, "zl", 2))
        size = sizeof (long long);
    else if (!ft_strncmp(state.qualifiers, "l", 2))
        size = sizeof (long);
    else if (!ft_strncmp(state.qualifiers, "h", 2))
        size = sizeof(short);
    else if (!ft_strncmp(state.qualifiers, "hh", 3))
        size = sizeof(char);
    else
        size = sizeof(int);
    printf("size: %zu | sizeofint: %zu | qualifiers: %s \n", size, sizeof(int), state.qualifiers);
    arg = va_arg(ap, void*);
    swp = ft_btoa(arg, size);
    output = ft_stoa(state, STRING, swp);
    free(swp);
    return (output);
}
