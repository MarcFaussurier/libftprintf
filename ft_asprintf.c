/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asprintf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:50:37 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 16:01:39 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_asprintf(char **strp, const char *fmt, ...)
{
	va_list			ap;
	int				output;

	va_start(ap, fmt);
	output = vasprintf(strp, fmt, ap);
	va_end(ap);
	return (output);
}
