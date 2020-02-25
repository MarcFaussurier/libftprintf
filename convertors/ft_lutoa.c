#include "libftprintf.h"

char        *ft_lutoa(unsigned long int n)
{
    return (ft_llutoa_base(b10, n));
}
