/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_int.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 10:04:31 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 10:05:36 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char 		*ft_fmt_int(t_fmt_state *state)
{
	int				i;

	i = va_arg(state->args, int);
	return (ft_itoa(i));
}
