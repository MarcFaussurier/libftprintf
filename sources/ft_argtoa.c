/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_argoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 09:52:15 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:01:38 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

static t_flags	ft_read_flags(char const **fmt)
{
	t_flags		o;

	o = (t_flags) {0, 0, 0, 0};
	while (**fmt)
	{
		if (**fmt == '0')
			o.zero = 1;
		else if (**fmt == '+')
			o.plus = 1;
		else if (**fmt == '-')
		{
			o.zero = 0;
			o.minus = 1;
		}
		else if (**fmt == '#')
			o.sharp = 1;
		else
			break;
		*fmt += 1;
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

char			*ft_argtoa(char const **fmt, va_list ap)
{
	t_flags		flags;
	int			precision;
	int			padding;
	char		*qualifiers;

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
	return ((ft_get_convertor(*(*fmt)++))((t_convertor_state) {
                .flags=flags, 
                padding, 
                precision, 
                qualifiers, 
    }, ap));
}
