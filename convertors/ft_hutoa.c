#include <libftprintf.h>

char        *ft_htoa(short n)
{
    return (ft_llitoa_base(b10, n));
}
