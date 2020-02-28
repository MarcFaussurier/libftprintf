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
    char        *o;
    char        *swp;
    wchar_t     d;
    wchar_t     *z;
    char        c;
	char		*s;

    if (!ft_strncmp(state.qualifiers, "l", 2))
    {
        z = (wchar_t[2]) {d = va_arg(ap, wchar_t), '\0'};
        if (!d)
        {
            s = (char[5]) {-42,-42,-42,-42,'\0'};
            return (ft_stoa(state, s, FALSE, TRUE));
        }
        else
        {
            swp = ft_wstrtoa(z);
            o = ft_stoa(state, swp, FALSE, FALSE);
            free(swp);
            return (o);
        }
    }
    else
    {
        s = (char[2]) {c = va_arg(ap, int), '\0'};
        if (!c)
            s[0] = -42;
    }
    return (ft_stoa(state, s, FALSE, !c));
}
