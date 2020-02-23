#include <libftprintf.h>


static char         *ft_read_ipart(long double n)
{
    size_t          i;
    size_t          s;
    long double     k;
    char            *out;
    char            c;

    if (n == 1)
        return (ft_strdup("1"));
    else if (!n)
        return (ft_strdup("0"));
    s = 1;
    k = n;
    while (k >= 1 && (k /= 10))
        s += 1;
    printf("s: %zu \n", s);
    out = malloc(s);
    i = 0;
    s -= 2;
    while (TRUE)
    {
        c = (char)  (n / ft_pow(10, s));
        out[i++] = '0' + c;
        n -= c * ft_pow(10, s);
        if (s)
            s -= 1;
        else
            break ;
        if (!n)
        {
            out[i++] = '0';
            break;
        }
    }
    out[i] = '\0';
    return (out);
}

static char         *ft_read_rest(long double n)
{
    size_t          s;
    long double     k;
    char            *out;
    char            c;

    if (n >= 1 || n <= 0)
        return ("");
    k = n;
    s = 1;
    while (k && s <= LDMAXPRECISION)
    {
        c = k * ft_pow(10,s);
        k -= c*ft_pow(10, -s);
        s += 1;
    }
    out = malloc(s);
    k = n;
    s = 1;
    while (k && s <= LDMAXPRECISION)
    {
        c = k * ft_pow(10,s);
        out[s - 1] = '0' + c;
        k -= c*ft_pow(10, -s);
        s += 1;
    }
    out[s - 1] = '\n';
    return (out);
}

char                *ft_ldtoa(long double n)
{
    long double     ipart;
    long double     rest;
    char            *output;
    char            *swp1;
    char            *swp2;
    char            *swp3;

    rest = ft_modfl(n, &ipart);
    printf ("ldtoa()... r=%Lf n=%Lf i=%Lf\n", rest, n, ipart);
    swp1 = ft_read_ipart(ipart);
    swp2 = ft_read_rest(rest);
    swp3 = ft_strjoin(swp1, ".");
    output = ft_strjoin(swp3, swp2);
    free(swp1);
    free(swp2);
    free(swp3);
    return (output);
}
