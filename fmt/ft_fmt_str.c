/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_str.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 10:07:49 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 10:08:10 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_fmt_str(t_fmt_state *state)
{
	char			*ptr;

	ptr = va_arg(state->args, char *);
	if (!ptr)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(ptr));
}
