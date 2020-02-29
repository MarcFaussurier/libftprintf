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
    int         i;
    wchar_t     y;

    if (!ft_strncmp(state.qualifiers, "l", 2))
    {
        y = va_arg(ap, wchar_t);
        if (y > UCHAR_MAX)
            return (NULL);
        return (ft_stoa(state, (char[2]) {y ? y : -42, '\0'}, FALSE, !y));
    }
    else
    {
        i = va_arg(ap, int);
        if (i > UCHAR_MAX)
            return (NULL);
        return (ft_stoa(state, (char[2]) {i ? i : -42, '\0'}, FALSE, !i));
    }
}
