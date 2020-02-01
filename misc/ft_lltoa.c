/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lltoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 15:44:14 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 16:02:37 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char                            *ft_lltoa(long long n)
{
        unsigned short  		numlen;
        size_t                  i;
        char                    *out;
        t_bool                  isn;

		printf("n: %lli\n", n);
        if (n == 0)
                return (ft_strdup("0"));
        numlen = ft_lllen(n);
        if (!(out = malloc(sizeof(char) * (numlen + 1))))
                return (NULL);
        isn = FALSE;
        if ((i = 0) || (n <= LLONG_MIN))
                return (ft_strdup("-9223372036854775807"));
        if (n < 0 && (isn = TRUE))
                out[i++] = '-';
        if (n < 0)
                n = -n;
        while (n)
        {
                out[numlen - i - !isn] = ('0' + n % 10);
                n /= 10;
                i += 1;
        }
        out[i] = '\0';
        return (out);
}
