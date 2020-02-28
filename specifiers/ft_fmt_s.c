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
    char        *swp;
    char        *o;

    if (!ft_strncmp(state.qualifiers, "ll", 3))
    {
        swp = ft_wstrtoa(va_arg(ap, wchar_t *));
        o = ft_stoa(state, swp, FALSE, FALSE);
        free(swp);
        return (o);
    }
    else
        return (ft_stoa(state, va_arg(ap, char *), FALSE, FALSE));
}
