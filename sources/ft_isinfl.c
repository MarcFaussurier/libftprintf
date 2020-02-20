#include <libftprintf.h>

t_bool                  ft_isinfl(long double x)
{
    return (ft_read_state_ld(x) == INFINITY);
}
