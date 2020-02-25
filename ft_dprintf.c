#include "libftprintf.h"

int             ft_dprintf(int fd, const char *fmt, ...)
{
    va_list     ap;
    int         oi;

    va_start(ap, fmt);
    oi = ft_vdprintf(fd, fmt, ap);
    va_end(ap);
    return (oi);
}
