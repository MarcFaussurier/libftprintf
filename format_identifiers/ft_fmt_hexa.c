/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_hexa.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 10:08:52 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 10:09:11 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

 char			*ft_fmt_hexa(t_fmt_state *state)
{
	unsigned long long		addr;
	char					*o;

	addr = (unsigned long long) va_arg(state->args, void *);
	o = ft_ubase(b16, addr, ULONG_LONG_MAX);
	state->output_len += ft_strlen(o);
	return (o);
}
