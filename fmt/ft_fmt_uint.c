/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_uint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 11:16:57 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 11:18:24 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

 char			*ft_fmt_uint(t_fmt_state *state)
{
	unsigned int			n;
	char					*o;

	n = (unsigned int) va_arg(state->args, unsigned int);
	o = ft_ubase(b10, n, UINT_MAX);
	return (o);
}

