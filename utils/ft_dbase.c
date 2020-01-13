/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dbase.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 11:22:57 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 11:58:36 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char					*ft_dbase(const char *base, double num)
{
	unsigned int		base_len;
	long long			n;
	char				*r;
	char				*s;

	base_len = ft_strlen(base);
	if (num == 0)
	{
		return (ft_strdup(""));
	}
	r = ft_dbase(base, num / base_len);
	if (num / base_len < 1 && num >= 1)
	{
		s = ft_strjoin(".", r);
		free(r);
	}
	else
		s = r;
	while (num < 1)
		num *= base_len;
	n = num;
	r = ft_strjoin((char[2]){base[n % base_len],'\0'}, s);
	free(s);
	return (r);
}
