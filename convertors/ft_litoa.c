#include "libftprintf.h"

char            *ft_litoa(long n)
{
    return (ft_llitoa_base(b10, n));
}
