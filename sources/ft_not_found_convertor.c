/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_not_found_convertor.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 12:53:51 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 12:56:56 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

char			*ft_not_found_convertor(t_flags flags, int padding, int precision, char *qualifiers)
{
	(void) flags;
	(void) padding;
	(void) precision;
	(void) qualifiers;
	return (ft_strdup(""));
}
