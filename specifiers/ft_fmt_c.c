/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 10:46:01 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 11:07:18 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_fmt_c(t_specifier_state state, va_list ap)
{
    char        *swp;
    char        *o;
    wchar_t        *z;
    wchar_t     y;
    int         i;

    if (!ft_strncmp(state.qualifiers, "l", 2))
    {
        y = va_arg(ap, wchar_t);
        if (!y)
            return (ft_stoa(state, (char[2]) {-42, '\0'}, FALSE, !y));
        z = (wchar_t[2]) {y, 0};
        swp = ft_wstrtoa(z);
        o = ft_stoa(state, swp, FALSE, FALSE);
        free(swp);
        return (o);
    }
    i = va_arg(ap, int);
    if (!i)
        return (ft_stoa(state, (char[2]) {-42, '\0'}, FALSE, !i));
    return (ft_stoa(state, (char[2]){i, '\0'}, FALSE, !i));
}
