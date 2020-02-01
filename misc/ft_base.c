/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_base.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 23:21:31 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 11:15:22 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char					*ft_base(const char *base, long long num, long long max)
{
	long long			rest;
	unsigned int		base_len;
	char				c;
	char				*r;
	char				*s;
	long long			min;

	min = - (2 * max) - 1;
	num = num > max ? min : num;
	num = num < min ? max : num;
	base_len = ft_strlen(base);
	rest = num / base_len;
	if (rest)
		s = ft_ubase(base, rest, max);
	else
		s = ft_strdup("");
	c = base[num % base_len];
	r = ft_strjoin(s, (char[2]){c, '\0'});
	free(s);
	return (r);
}
