/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_octal.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 11:06:55 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 11:17:52 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

 char			*ft_fmt_octal(t_fmt_state *state)
{
	unsigned int			n;
	char					*o;

	n = (unsigned int) va_arg(state->args, unsigned int);
	o = ft_ubase(b8, n, UINT_MAX);
	return (o);
}
