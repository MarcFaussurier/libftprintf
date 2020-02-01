/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_char.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 10:07:09 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 10:07:36 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_fmt_char(t_fmt_state *state)
{
	char			c;
	char			*output;

	c = va_arg(state->args, int);
	output = malloc(2 * sizeof(char));
	if (!output)
		return (output);
	output[0] = c;
	output[1] = '\0';
	return (output);
}
