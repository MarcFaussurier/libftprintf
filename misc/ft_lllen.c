/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lllen.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/01 15:57:31 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 16:00:44 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "libftprintf.h"

size_t					ft_lllen(long long n)
{
	size_t				out;

	out = 0;
	if (n == LLONG_MIN)
		return (ft_strlen("-9223372036854775807"));
	if (n < 0 && (n = -n))
		out += 1;
	while (n)
	{
		out += 1;
		n /= 10;
	}
	return (out);
}
