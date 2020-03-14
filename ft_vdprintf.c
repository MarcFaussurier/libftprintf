#include "libftprintf.h"

int             ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	int			oi;
	char    	*ob;

	oi = ft_vasprintf(&ob, fmt, ap);
	if (oi)
        ft_putmem_fd(fd, ob, oi);
    free(ob);
    return (oi);
}
