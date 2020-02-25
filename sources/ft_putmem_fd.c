#include <libftprintf.h>

void            ft_putmem_fd(int fd, char *mem, size_t n)
{
    write(fd, mem, n);
}
