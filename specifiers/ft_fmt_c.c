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
    char        c;
	char		*s;
	char		*out;

	s = (char[2]) {c = va_arg(ap, int), '\0'};
    state.precision = 1;
    if (!c)
        s[0] = -42;
	out = ft_stoa(state, s, FALSE, TRUE);
	return (out);
}
