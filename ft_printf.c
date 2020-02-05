/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 08:25:45 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 09:53:05 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

int					ft_printf(const char *fmt, ...)
{
	int				output;
	va_list			ap;

	va_start(ap, fmt);
	output = ft_vprintf(fmt, ap);
	va_end(ap);
	return (output);
}
