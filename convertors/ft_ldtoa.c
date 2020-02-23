#include <libftprintf.h>


static char         *ft_read_ipart(const char *b, long double n)
{
    size_t          bl;
    size_t          i;
    size_t          s;
    long double     k;
    char            *out;
    char            c;

    bl = ft_strlen(b);
    if (n == 1)
        return (ft_strdup("1"));
    else if (!n)
        return (ft_strdup("0"));
    s = 1;
    k = n;
    while (k >= 1 && (k /= bl))
        s += 1;
    printf("s: %zu \n", s);
    out = malloc(s);
    i = 0;
    s -= 2;
    while (TRUE)
    {
        c = (char)  (n / ft_pow(bl, s));
        out[i++] = b[(short)c];
        n -= c * ft_pow(bl, s);
        if (s)
            s -= 1;
        else
            break ;
        if (!n)
        {
            out[i++] = b[0];
            break;
        }
    }
    out[i] = '\0';
    return (out);
}

static char         *ft_read_rest(const char *b, long double n)
{
    size_t          bl;
    size_t          s;
    long double     k;
    char            *out;
    char            c;

    if (n >= 1 || n <= 0)
        return ("");
    bl = ft_strlen(b);
    k = n;
    s = 1;
    while (k && s <= LDMAXPRECISION)
    {
        c = k * ft_pow(bl,s);
        k -= c*ft_pow(bl, -s);
        s += 1;
    }
    out = malloc(s);
    k = n;
    s = 1;
    while (k && s <= LDMAXPRECISION)
    {
        c = k * ft_pow(bl,s);
        out[s - 1] = b[(short)c];
        k -= c*ft_pow(bl, -s);
        s += 1;
    }
    out[s - 1] = '\n';
    return (out);
}

char                *ft_ldtoa_base(const char *b, long double n)
{
    long double     ipart;
    long double     rest;
    char            *output;
    char            *swp1;
    char            *swp2;
    char            *swp3;

    rest = ft_modfl(n, &ipart);
    printf ("ldtoa()... r=%Lf n=%Lf i=%Lf\n", rest, n, ipart);
    swp1 = ft_read_ipart(b, ipart);
    swp2 = ft_read_rest(b, rest);
    swp3 = ft_strjoin(swp1, ".");
    output = ft_strjoin(swp3, swp2);
    free(swp1);
    free(swp2);
    free(swp3);
    return (output);
}

char            *ft_ldtoa(long double n)
{
    return (ft_ldtoa_base(b10, n));
}
