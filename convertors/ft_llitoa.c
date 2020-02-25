#include "libftprintf.h"

char        *ft_llitoa(long long n)
{
    return (ft_llitoa_base(b10, n));
}
