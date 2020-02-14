#include <libftprintf.h>

char        *ft_ldtoa(long double n)
{
    return (ft_ldtoa_base(b10, n));
}
