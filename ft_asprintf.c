/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asprintf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 19:03:44 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 19:11:58 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int						ft_asprintf(char **strp, const char *fmt, ...)
{
	va_list				ap;
	int					output;

	va_start(ap, fmt);
	output = ft_vasprintf(strp, fmt, ap);
	va_end(ap);
	return (output);
}
