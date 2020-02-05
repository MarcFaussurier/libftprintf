/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_boot_convertors.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 12:30:03 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 12:34:24 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

char			*ft_fmt_s(t_flags flags, int padding, int precision, char *qualifiers)
{
	(void) flags;
	(void) padding;
	(void) precision;
	(void) qualifiers;
	return (ft_strdup("string test"));
}

void			ft_boot_convertors()
{
	printf("registring convertors...\n");
	ft_register_convertor((t_assoc_convertor){'s', &ft_fmt_s});
	printf("convertors size: %i\n", ft_lstsize(g_convertors));
}
