/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 10:58:37 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 14:05:56 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_fmt_s(t_specifier_state state, va_list ap)
{
    char        *i;
    char        *o;
    wchar_t     *y;
    size_t      b;

    if (!ft_strncmp(state.qualifiers, "l", 2))
    {
        y = va_arg(ap, wchar_t *);
        b = 0;
        while (y[b])
        {
            if (y[b] > UCHAR_MAX)
                return (NULL);
            b += 1;
        }
        i = malloc(b + 1);
        b = 0;
        while (y[b])
        {
            i[b] = y[b];
            b += 1;
        }
        i[b] = 0;
        o = ft_stoa(state, i, FALSE, FALSE);
        free(i);
        return (o);
    }
    else
        return (ft_stoa(state, va_arg(ap, char *), FALSE, FALSE));
}
