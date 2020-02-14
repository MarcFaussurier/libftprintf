/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_u.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 10:03:23 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 10:14:49 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

char			*ft_fmt_u(t_specifier_state state, va_list ap)
{
	char		*num;
	char		*out;

	printf("qualifiers: %s\n", state.qualifiers);
	if (!(ft_strncmp(state.qualifiers, "ll", 3)))
		num = ft_llutoa(va_arg(ap, unsigned long long));
	else if (!(ft_strncmp(state.qualifiers, "l", 2)))
		num = ft_lutoa(va_arg(ap, unsigned long));
	else if (!ft_strlen(state.qualifiers))
		num = ft_utoa(va_arg(ap, unsigned int));
	else if (!(ft_strncmp(state.qualifiers, "h", 2)))
		num = ft_hutoa(va_arg(ap, unsigned int));
	else if (!(ft_strncmp(state.qualifiers, "hh", 3)))
		num = ft_hhutoa(va_arg(ap, unsigned int));
	else
		num = NULL;
	if (!num)
		return (NULL);
	out = ft_stoa(state, num, TRUE);
	free(num);
	return (out);
}
