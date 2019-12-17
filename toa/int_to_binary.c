/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int_to_binary.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:41:34 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:33:18 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
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

char						*ft_itoba(void *arg)
{
	return (ft_reccursive_itoba(*((int*) arg), 0));
}
