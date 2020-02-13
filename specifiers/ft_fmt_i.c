/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_i.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/07 11:00:30 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 11:24:07 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

char			*ft_fmt_i(t_specifier_state state, va_list ap)
{
	char		*output;
	char		fillwith;
	int			realwidth;

	if (!ft_strlen(state.qualifiers))
	{
		output = ft_itoa(va_arg(ap, int));
		fillwith = ' ';
		realwidth = state.padding;
		if (state.precision != NO_PRECISION && (realwidth = state.precision))
			fillwith = '0';
		if (realwidth > (int)ft_strlen(output))
		{

		}
	}
	else
		output = ft_strdup("");
	return (output);
}
