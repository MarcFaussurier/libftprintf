/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_argoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 09:52:15 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 12:23:16 by mfaussur    ###    #+. /#+    ###.fr     */
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
	char		*qualifiers;
	char		specifier;
	int			precision;
	int			padding;

	flags = ft_read_flags(fmt);
	padding = ft_read_num(fmt, ap);
	precision = **fmt == '.' && ++*fmt ? ft_read_num(fmt, ap) : NO_PRECISION;
	if (!(qualifiers = ft_read_qualifiers(fmt)))
		return (NULL);
	return ((ft_is_specifier(specifier = *(*fmt)++) ? 
	(ft_get_specifier(specifier))((t_specifier_state) {
    		.flags=flags,
			.qualifiers=qualifiers,
			.specifier=specifier,
        	.padding=padding, 
        	.precision=precision, 
        	.no=no,
    	}, ap) : ft_strdup("")) + ft_free(qualifiers, 0));
}
