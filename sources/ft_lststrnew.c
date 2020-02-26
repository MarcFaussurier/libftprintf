#include "libftprintf.h"

t_list			*ft_lststrnew(unsigned int n, ...)
{
	t_list		*o;
	va_list		ap;

	va_start(ap, n);
	o = ft_vlststrnew(n, ap);
	va_end(ap);
	return (o);
}
