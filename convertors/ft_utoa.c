#include "libftprintf.h"

char            *ft_utoa(unsigned int n)
{
    return (ft_llutoa_base(b10, n));
}
