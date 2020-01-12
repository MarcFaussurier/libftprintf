/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_register_defaults.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:37:30 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/12 15:40:55 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static char 		*ft_test(t_fmt_state *state)
{
	return ("42");
}

t_bool				ft_register_defaults()
{
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'},'i', ft_test}))
		return (FALSE);
	return (TRUE);
}
