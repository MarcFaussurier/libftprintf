/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_asprintf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 10:16:20 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 10:18:01 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

int					ft_asprintf(char const **ob, const char *fmt, ...)
{
	int				output;
	va_list			ap;

	va_start(ap, fmt);
	output = ft_vasprintf(ob, fmt, ap);
	va_end(ap);
	return (output);
}
