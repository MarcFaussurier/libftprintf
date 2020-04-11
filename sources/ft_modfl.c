#include "libftprintf.h"


char            *ft_read_decimal(long double n, const char *b, size_t bl)
{
    size_t          s;
    long double     k;
    char            *out;
    unsigned short  c;

	if (n == (long double) 0)
        return (ft_strdup("0"));
    if (n >= 1 || n < 0)
    {
        printf("inputerror ft_rd:14 %Lf\n", n);
        return (ft_strdup("ERROR INVALID INPUT"));
    }
    printf("printing decimal... %Lf\n", n);
    bl = ft_strlen(b);
    k = n;
    s = 1;
	while (k != ((long double) 0) && s <= LDMAXPRECISION)
    {
        c = k * ft_pow(bl, s);
        k -= c * ft_pow(bl, -s);
        s += 1;
    }
    printf("number of digits afterdot: %zu\n", s);
    out = malloc(s + 2);
	k = n;
    s = 1;
    while (k != ((long double) 0) && s <= LDMAXPRECISION)
    {
        c = k * ft_pow(bl, s);
        out[s - 1] = b[c];
        k -= c * ft_pow(bl, -s);
        s += 1;
    }
    out[s - 1] = '\0';
	return (out);
}

char            *ft_modld_toa(long double n, long double *i, long double *r, const char *b)
{
    size_t          bl;
    int             s;
    int             p;
    long double     k;
    unsigned char   c;
    long double     e;
    t_bool          isn;
    char            *o[4];

    o[1] = ".";

    bl = b ? ft_strlen(b) : 10;
    if (n == 1)
    {
        *i = 1;
        *r = 0;
        return (b ? ft_strnew(3, (char[2]){b[1], 0}, o[1], (char[2]){b[0], 0}) : NULL);
    }
    else if (n >= 0 && n < 1)
    {
        *i = 0;
        *r = n;
        o[3] = (b ? ft_strnew(3, (char[2]){b[0], 0}, o[1], o[2] = ft_read_decimal(n, b, bl)) : NULL);
        free(o[2]);
        return (o[3]);
    }
    else if (n < 0)
    {
        isn = TRUE;
        n = -n;
    }

    p = 0;
    k = n;
    while (k >= 1)
    {
        p += 1;
        k = k / bl;
    }
    s = p;
    if (b)
    {
        o[0] = malloc(p + 2 + isn);
        o[0][p + 1 + isn] = 0;
        p += isn;
        if (isn)
            o[0][0] = '-';
    }

    k = n;
    while (s >= 0)
    {
        e = ft_pow(bl, s);
        c = k / e;
        if (b)
            o[0][p - s] = b[c];
        k -= c * e;
        s -= 1;
    }
    *r = k;
    *i = n - *r;
    if (isn)
    {
        *i *= -1;
    }
    if (b)
    {
        o[3] = ft_strnew(3, o[0], o[1], o[2] = ft_read_decimal(*r, b, bl));
        free(o[0]);
        free(o[2]);
        return (o[3]);
    }
    return (NULL);
}

long double         ft_modfl(long double n, long double *int_part)
{
    long double     r;

    ft_modld_toa(n, int_part, &r, NULL);
    return (r);
}
