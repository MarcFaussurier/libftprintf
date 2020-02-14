/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_argoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 09:52:15 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 10:37:51 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>

static t_flags	ft_read_flags(char const **fmt)
{
	t_flags		o;
    char        c;


	o = (t_flags) {0, 0, 0, 0};
	while ((c = *(*fmt)++))
		if (c == '0')
			o.zero = 1;
		else if (c == '+')
			o.plus = 1;
		else if (c == '-')
		{
			o.zero = 0;
			o.minus = 1;
		}
		else if (c == '#')
			o.sharp = 1;
		else
        {
            *fmt -= 1;
            break;
	    }
    return (o);
}

static int		ft_read_num(char const **fmt, va_list ap)
{
	char		len = 0;
	char		*swp;
	char const	*bkp;
	int			o;

	bkp = *fmt;
	if (**fmt == '*' && ++(*fmt))
		return (va_arg(ap, int));
	while (ft_isdigit(**fmt) && (++*fmt) && (++len))
	    ;
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
		qualifiers[i++] = *(*fmt)++;
	return (qualifiers);
}

char			*ft_argtoa(char const **fmt, va_list ap, int no)
{
	t_flags		flags;
	int			precision;
	int			padding;
	char		*qualifiers;

	flags = ft_read_flags(fmt);
	padding = ft_read_num(fmt, ap);
	precision = NO_PRECISION;
	if (**fmt == '.' && ++*fmt)
		precision = ft_read_num(fmt, ap);
	qualifiers = ft_read_qualifiers(fmt);
	if (!qualifiers)
		return (NULL);
	if (!ft_is_specifier(**fmt))
	{
		free(qualifiers);
		*fmt += 1;
		return (ft_strdup(""));
	}
	return ((ft_get_specifier(*(*fmt)++))((t_specifier_state) {
                .flags=flags, 
                padding, 
                precision, 
                qualifiers,
				.no=no,
    }, ap));
}
