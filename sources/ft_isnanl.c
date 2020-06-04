#include "libftprintf.h"

t_bool          ft_isnanl(long double x)
{
    return (!ft_is_in_a(ft_read_state_ld(x), (int[5]){FP_NORMAL, FP_SUBNORMAL, FP_ZERO, FP_INFINITY, FP_MINUS_INFINITY}, 5));
}
