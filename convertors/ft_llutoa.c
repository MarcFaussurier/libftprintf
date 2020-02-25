#include "libftprintf.h"

char        *ft_llutoa(unsigned long long int n)
{
    return (ft_llutoa_base(b10, n));
}
