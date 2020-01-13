/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_ptr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 10:08:21 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 10:08:34 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

 char			*ft_fmt_ptr(t_fmt_state *state)
{
	unsigned long long		addr;
	char					*o;
	char					*swp;

	addr = (unsigned long long) va_arg(state->args, void *);
	o = ft_ubase(b16, addr, ULONG_LONG_MAX);
	if (o)
	{
		swp = ft_strjoin("0x", o);
		free(o);
		o = swp;
	}
	state->output_len += ft_strlen(o);
	return (o);
}
