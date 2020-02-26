#include "libftprintf.h"

char		*ft_vstrnew(unsigned int n, va_list ap)
{
	return (ft_lststrjoin(ft_vlststrnew(n, ap)));
}
