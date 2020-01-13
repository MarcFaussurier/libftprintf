/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itob.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 14:32:25 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 14:33:05 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static char					*ft_reccursive_itoba(int i, unsigned char index)
{
	char					*out;

	if (index >= sizeof(int) * 8)
	{
		printf("\n");
		out = malloc((index + 1) * sizeof(char));
		out[index] = '\0';
		return (out);
	}
	out = ft_reccursive_itoba(i >> 1, index + 1);
	out[sizeof(int) * 8 - index - 1] = (i & 1 ? 1 : 0) + '0';
	return (out);
}

char						*ft_itob(int i)
{
	return (ft_reccursive_itoba(i, 0));
}
