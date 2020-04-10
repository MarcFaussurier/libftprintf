#include "libftprintf.h"

int             main()
{
    long double n;
    long double p;

    n = 229;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 467484574.7684847;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 8758945659845689465.6854578456897846978;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 87568465.68456897846978;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 0.54688648646;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 1.445844;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 10.748745786478;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 19.784586742578454;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 29.4586745458;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 129.8458747;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
    n = 1299852221564.8458747;
    ft_printf("%Lf\n", n);
    printf("%Lf | r=%Lf i=%Lf\n", n, ft_modfl(n, &p), p);
}
