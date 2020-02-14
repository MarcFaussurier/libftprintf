/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fmt_n.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 11:05:35 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 11:14:13 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

char			*ft_fmt_n(t_specifier_state state, va_list ap)
{
	int			*ptr;
//	char		*num;
//	char		*out;

	ptr = va_arg(ap, int*);
	*ptr = state.no;
//	num = ft_itoa(state.no);
//	out = ft_stoa(state, num, TRUE);
//	free(num);
//	return (out);
	return (ft_strdup(""));
}
