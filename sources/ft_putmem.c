#include "libftprintf.h"

void            ft_putmem(char *s, size_t n)
{
    ft_putmem_fd(STDIN_FILENO, s, n);
}
