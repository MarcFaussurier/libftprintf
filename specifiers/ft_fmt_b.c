#include "libftprintf.h"

char        *ft_fmt_b(t_specifier_state state, va_list ap)
{
    char    *output;
    char    *swp;
    size_t  size;
    void    *arg;

    arg = va_arg(ap, void*);
    if (state.flags.sharp)
    {

        size = va_arg(ap, size_t);
        printf("found sharp... %zu\n", size);
    }
    else if (!ft_strlen(state.qualifiers) || !ft_strncmp(state.qualifiers, "l", 2))
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

    printf("size: %zu | %Lf | %zu\n", size, *((long double*)arg), sizeof(long double));
    swp = ft_btoa(arg, size);
    output = ft_stoa(state, STRING, swp);
    free(swp);
    return (output);
}
