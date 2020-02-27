/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_i.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 11:00:30 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 10:15:30 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_fmt_i(t_specifier_state state, va_list ap)
{
	char		*num;
	char		*out;

	if (!(ft_strncmp(state.qualifiers, "ll", 3)))
		num = ft_llitoa(va_arg(ap, long long));
	else if (!(ft_strncmp(state.qualifiers, "l", 2)))
		num = ft_litoa(va_arg(ap, long));
	else if (!ft_strlen(state.qualifiers))
		num = ft_itoa(va_arg(ap, int));
	else if (!(ft_strncmp(state.qualifiers, "h", 2)))
		num = ft_hitoa(va_arg(ap, int));
	else if (!(ft_strncmp(state.qualifiers, "hh", 3)))
		num = ft_hhitoa(va_arg(ap, int));
	else
		num = NULL;
	if (!num)
		return (NULL);
    out = ft_stoa(state, num, TRUE, FALSE);
	free(num);
	return (out);
}
