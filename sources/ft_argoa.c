/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_argoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 09:52:15 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 12:42:25 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

static t_flags	ft_read_flags(char const **fmt)
{
	char const	*bfmt;
	t_flags		o;

	o = (t_flags) {0, 0, 0, 0};
	bfmt = *fmt;
	while (*bfmt)
	{
		if (*bfmt == '0')
			o.zero = 1;
		else if (*bfmt == '+')
			o.zero = 1;
		else if (*bfmt == '-')
		{
			o.zero = 0;
			o.minus = 1;
		}
		else if (*bfmt == '#')
			o.sharp = 1;
		else
			break;
		*fmt += 1;
		bfmt += 1;
	}
	return (o);
}

static int		ft_read_num(char const **fmt)
{
	char		len = 0;
	char		*swp;
	char const	*bkp;
	int			o;

	bkp = *fmt;
	while (ft_isdigit(**fmt))
	{
		*fmt += 1;
		len += 1;
	}
	swp = ft_substr(bkp, 0, len);
	o = ft_atoi(swp);
	free(swp);
	return (o);
}

static char*	ft_read_qualifiers(char const **fmt)
{
	char *qualifiers;
	unsigned char		i;

	i = 0;
	qualifiers = ft_calloc(3, 1);
	while (!ft_is_specifier(**fmt) && i < 2)
	{
		qualifiers[i++] = **fmt;
		*fmt += 1;
	}
	return (qualifiers);
}
/*
static char		ft_read_specifier(char const **fmt)
{
	(void) fmt;
	return ('l');
}*/

char			*ft_argtoa(char const **fmt, va_list ap)
{
	t_flags		flags;
	int			precision;
	int			padding;
	char		*qualifiers;
	char		specifier;

	(void) ap;
	flags = ft_read_flags(fmt);
	padding = ft_read_num(fmt);
	precision = NO_PRECISION;
	if (**fmt == '.' && ++*fmt)
		precision = ft_read_num(fmt);
	qualifiers = ft_read_qualifiers(fmt);
	if (!qualifiers)
		return (NULL);
	if (!ft_is_specifier(**fmt))
	{
		free(qualifiers);
		*fmt += 1;
		return (ft_strdup(""));
	}
	specifier = **fmt;
	return ((ft_get_convertor(specifier))(flags, padding, precision, qualifiers ,ap));
}
