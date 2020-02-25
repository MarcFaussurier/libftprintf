#include "libftprintf.h"

t_bool          ft_isnanl(long double x)
{
    return (!ft_is_in_a(ft_read_state_ld(x), (int[3]){NORMAL, DENORMAL, ZERO}, 3));
}
