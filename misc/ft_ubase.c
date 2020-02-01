/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_base.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 23:21:31 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 11:15:02 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char					*ft_ubase(const char *base, unsigned long long num, unsigned long long max)
{

	unsigned long long	rest;
	unsigned int		base_len;
	char				c;
	char				*r;
	char				*s;

	num = num > max ? 0 : num;
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


