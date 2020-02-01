/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_double.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 11:19:12 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 11:33:07 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_fmt_double(t_fmt_state *state)
{
	double		n;
	char					*o;

	n = (double) va_arg(state->args, double);
	o = ft_dbase(b10, n);
	return (o);
}
