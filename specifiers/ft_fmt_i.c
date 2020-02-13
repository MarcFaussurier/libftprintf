/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_i.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 11:00:30 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:24:07 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

char			*ft_fmt_i(t_specifier_state state, va_list ap)
{
	char		*num;
	char		*out;

	if (!(ft_strncmp(state.qualifiers, "ll", 2)))
		num = ft_llitoa(va_arg(ap, long long));
	else if (!(ft_strncmp(state.qualifiers, "l", 1)))
		num = ft_litoa(va_arg(ap, long));
	else if (!ft_strlen(state.qualifiers))
		num = ft_itoa(va_arg(ap, int));
	else if (!(ft_strncmp(state.qualifiers, "h", 1)))
		num = ft_hitoa(va_arg(ap, int));
	else if (!(ft_strncmp(state.qualifiers, "hh", 2)))
		num = ft_hhitoa(va_arg(ap, int));
	else
		num = NULL;
	if (!num)
		return (NULL);
	out = ft_stoa(state, num, TRUE);
	free(num);
	return (out);
}
