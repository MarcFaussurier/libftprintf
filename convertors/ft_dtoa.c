#include <libftprintf.h>

char        *ft_dtoa(double n)
{
    return (ft_dtoa_base(b10, n));
}
