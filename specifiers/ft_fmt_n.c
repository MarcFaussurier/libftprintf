/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_n.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 11:05:35 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/03 17:14:03 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_fmt_n(t_specifier_state state, va_list ap)
{
    int         *ptr;
    t_list      *str;

    str = state.str;
    ptr = va_arg(ap, int*);
    if (ptr && ((*ptr = 0) || 1))
        while ((str && ((*ptr += ft_strlen((char*)str->content)) || 1)))
            str = str->next;
    return (ft_strdup(""));
}
