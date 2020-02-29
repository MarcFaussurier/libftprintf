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
#include <locale.h>
int             g_errors = 0;

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
    if ((i1 = ft_vasprintf(&s1, fmt, ap)) != (i2 = vasprintf(&s2, fmt, ap2)) || (i1 >= 0 && (diff = memcmp(s1, s2, i1))))
    {
        g_errors += 1;
        printf("[test line %i] invalid output: {%i} [r=%i | libc: r=%i]\n", *nb, diff, i1, i2);
        ft_putstr("YOUR: ");
        ft_putmem(s1, i1);
        ft_putendl("");
        ft_putstr("LIBC: ");
        ft_putmem(s2, i2);
        ft_putendl("");
    }
    else
    {
        printf ("[test line %i] success r=%i\t| \"%s\"\n", *nb, i2, s2);
    }
    free(s1);
    free(s2);
    va_end(ap);
    va_end(ap2);
}

int isLittleEndian()
{
    short int number = 0x1;
    char *numPtr = (char*)&number;
    return (numPtr[0] == 1);
}

int 			main(void)
{
    char        *s;
    int         n;
    printf("sizeof (wchar) : %zu is_little_endian: %i\n", sizeof(wchar_t), isLittleEndian());
    n = 66; //SET ME AS CURRENT LOC!
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
	test(&n, "%--1s", "");
	test(&n, "%5s", "Hello");
	test(&n, "%6s", "Hello");
	test(&n, "%1i", -101);
    test(&n, "%1i", 0);
	test(&n, "%2i", 0);
	test(&n, "%10i", 0);
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
 	test(&n, "%12.2slol\n", NULL);
	test(&n, "%--8.10slol\n", NULL);
	test(&n, "%8.10s\n", NULL);
	test(&n, "%*.*slol\n", -16, 3, NULL);
	test(&n, "%*.*hilol\n", -16, 2, 4242);
	test(&n, "%*.*hhulol\n", -16, 2, INT_MAX);
	test(&n, "%0-*.*c		%n	lol\n", -10, -5, 'q', &n);
    test(&n, "%0-16p %x %X %#x %#X\n", ULONG_LONG_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
    test(&n, "%0-16p %x %X %#x %#X\n", ULONG_LONG_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
    test(&n, "[%.2Lf]\n",   44.5605L);
    test(&n, "[%.2Lf]\n",   44.5405L);
    test(&n, "21?: %Lf\n", 21.42L);
    test(&n, "1");
    test(&n, "%lclol%lc", 0, 0);
    test(&n, "%lc", '\\');
    test(&n, "%lc", 0x0376);
    test(&n, "%lc", 0x0376);
    test(&n, "%lc", WCHAR_MAX);
    test(&n, "%ls", (wchar_t[2]){'/', 0});
    test(&n, "%lc", INT_MAX / 2);
    test(&n, "%lc", INT_MAX - 2);
    test(&n, "%lc", WCHAR_MAX);
    test(&n, "%lc", 316);
    test(&n, "%llllllllllllllli", LLONG_MAX);
    test(&n, "%hhhhhhhhi", LLONG_MAX);
    test(&n, "%zzwwwi", LLONG_MAX);
    test(&n, "%zzzzzu", ULONG_LONG_MAX);
    test(&n, "%lllllllllllllllx", LLONG_MAX);
    test(&n, "%hhhhhhhhi", LLONG_MAX);
    test(&n, "%zzwwwx", LLONG_MAX);
    printf("%i errors\n", g_errors);
}
