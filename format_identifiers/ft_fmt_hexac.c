/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_hexac.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 10:09:31 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 10:10:13 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

 char			*ft_fmt_hexac(t_fmt_state *state)
{
	unsigned long long		addr;
	char					*o;

	addr = (unsigned long long) va_arg(state->args, void *);
	o = ft_ubase(B16, addr, ULONG_LONG_MAX);
	state->output_len += ft_strlen(o);
	return (o);
}
