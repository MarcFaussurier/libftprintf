#include "libftprintf.h"

t_bool                  ft_isinfl(long double x)
{
    return (ft_is_in_a(ft_read_state_ld(x), (int[1]){INFINITY}, 1));
}
