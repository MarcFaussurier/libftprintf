#include "libftprintf.h"

char                  	*ft_strnew(unsigned int n, ...)
{
	va_list		ap;
	char		*o;

	va_start(ap, n);
	o = ft_vstrnew(n, ap);
	va_end(ap);
	return (o);
}
