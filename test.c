/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 09:18:18 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 11:11:04 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

void            test(int *nb, const char *fmt, ...)
{
    va_list     ap;
    va_list     ap2;
    char        *s1;
    char        *s2;
    int         i1;
    int         i2;
    int         diff;
    
    *nb += 1;
    va_start(ap2, fmt);
    va_start(ap, fmt);
    diff = 0;
    if ((i1 = ft_vasprintf(&s1, fmt, ap)) != (i2 = vasprintf(&s2, fmt, ap2)) || (diff = memcmp(s1, s2, i1)))
    {
        printf("[test line %i] invalid output: {%i} [r=%i | libc: r=%i]\n", *nb, diff, i1, i2);
        ft_putstr("YOUR: ");
        ft_putmem(s1, i1);
        ft_putendl("");
        ft_putstr("LIBC: ");
        ft_putmem(s2, i2);
        ft_putendl("");
    }
    else
        printf ("[test line %i] success r=%i\t| \"%s\"\n", *nb, i2, s2);
    free(s1);
    free(s2);
    va_end(ap);
    va_end(ap2);
}

int 			main(void)
{
    char        *s;
    int         n;

    n = 54; //SET ME AS CURRENT LOC!
    test(&n, "");
    test(&n, "1");
    test(&n, "%s", "hello");
    test(&n, "%s", (char[3]) {'\0', 'a', '\0'});
    test(&n, "%10c lol %c 1", 0, 0);
    test(&n, "%*c", -1000, 'a');
    test(&n, "%-*s", -1000, "a");
    test(&n, "%-*s", -1000, "");
    test(&n, "%1%");
    test(&n, "%2%");
    test(&n, "%10%");
    test(&n, "%1c", '1');
	test(&n, "%2c", '1');
    test(&n, "%10c", '1');
	test(&n, "%1s", "");
	test(&n, "%5s", "Hello");
	test(&n, "%6s", "Hello");
	test(&n, "%1i", 0);
	test(&n, "%2i", 0);
	test(&n, "%10i", 0);
	test(&n, "%1i", -101);
    test(&n, "%1i", -1);
	test(&n, "%2i", -1);
	test(&n, "%3i", -1);
	test(&n, "%9i", INT_MAX);
	test(&n, "%10i", INT_MAX);
	test(&n, "%11i", INT_MAX);
	test(&n, "%1d", 0);
	test(&n, "%2d", 0);
	test(&n, "%10d", 0);
	test(&n, "%1d", -1);
	test(&n, "%2d", -1);
	test(&n, "%3d", -1);
	test(&n, "%9d", INT_MAX);
	test(&n, "%10d", INT_MAX);
	test(&n, "%11d", INT_MAX);
	test(&n, "%1u", 0);
	test(&n, "%2u", 0);
	test(&n, "%10u", 0);
	test(&n, "%1u", -1);
    test(&n, "%2u", -1);
    test(&n, "%3u", -1);
	test(&n, "%9u", UINT_MAX);
	test(&n, "%10u", UINT_MAX);
	test(&n, "%11u", UINT_MAX);
	test(&n, "%1x", 0);
	test(&n, "%2x", 0);
	test(&n, "%10x", 0);
	test(&n, "%1x", -1);
	test(&n, "%2x", -1);
	test(&n, "%3x", -1);
	test(&n, "%9x", UINT_MAX);
	test(&n, "%10x", UINT_MAX);
	test(&n, "%11x", UINT_MAX);
	test(&n, "%1X", 0);
	test(&n, "%2X", 0);
	test(&n, "%10X", 0);
	test(&n, "%1X", -1);
	test(&n, "%2X", -1);
    test(&n, "%3X", -1);
	test(&n, "%9X", UINT_MAX);
	test(&n, "%10X", UINT_MAX);
	test(&n, "%11X", UINT_MAX);
	test(&n, "%1p", (void*)42);
	test(&n, "%5p", (void*)42);
    /*
    printf("ft_llitoa_base: %s\n", ft_llitoa_base(b10, 258888588454));
 	a = ft_printf("%12.2slol\n", NULL);
	b = printf("%12.2slol\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%--8.10slol\n", NULL);
	b = printf("%--8.10slol\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%8.10s\n", NULL);
	b = printf("%8.10s\n", NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%*.*slol\n", -16, 3, NULL);
	b = printf("%*.*slol\n", -16, 3, NULL);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%*.*hilol\n", -16, 2, 4242);
	b = printf("%*.*hilol\n", -16, 2, 4242);
	printf("\n[outputs: %i %i]\n", a, b);

	a = ft_printf("%*.*hhulol\n", -16, 2, INT_MAX);
	b = printf("%*.*hhulol\n", -16, 2, INT_MAX);
	printf("\n[outputs: %i %i]\n", a, b);

	int		n;
	a = ft_printf("%0-*.*c		%n	lol\n", -10, -5, 'q', &n);
	b = printf("%0-*.*c		%n	lol\n", -10, -5, 'q', &n);
	printf("\n[outputs: %i %i]\n", a, b);

    a = ft_printf("%0-16p %x %X %#x %#X\n", ULONG_LONG_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
    b = printf("%0-16p %x %X %#x %#X\n", ULONG_LONG_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
    printf("\n[outputs: %i %i]\n", a, b);

    long double     k;
    long double     i;
    long double     q;
    k = 10.2658;
    q = ft_modfl(k, &i);
    
    
    printf("testing ft_modfl(%Lf)... [q=%Lf | i=%Lf]\n", k, q, i);
    ft_printf("\n[%Lf]\n",   44.5565899999999999999999999999999999999999999999999999999L);
    printf("\n%.256Lf\n",  44.5565899999999999999999999999999999999999999999999999999L);
    ft_printf("21?: %Lf\n", 21.42L);
    printf("%a %La %s||\n", 21.42, 21.42L, ft_ldtoa_base(b16, 21.42L));
    printf("%Lf\n", 10.0L);
    ft_printf("1");
    printf("1");*/
}
