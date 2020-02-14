#include <libftprintf.h>

char        *ft_hutoa(unsigned short n)
{
    return (ft_llutoa_base(b10, n));
}
