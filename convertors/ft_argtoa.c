/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_argoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 09:52:15 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/09 15:04:09 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	ft_read_flags(char const **fmt)
{
	t_flags		o;
    char        c;

	o = (t_flags) {0, 0, 0, 0, 0};
	while ((c = *(*fmt)++))
		if (c == '0')
			o.zero = o.minus ? 0 : 1;
		else if (c == '+')
			o.plus = 1;
		else if (c == '-')
		{
			o.zero = 0;
			o.minus = 1;
		}
		else if (c == '#')
			o.sharp = 1;
		else if (c == ' ')
			o.space = 1;
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
	while ((ft_isdigit(**fmt) || **fmt == '-') && (++*fmt) && (++len))
	    ;
    swp = ft_substr(bkp, 0, len);
	o = ft_atoi(swp);
	free(swp);
	return (o);
}

static char*	        ft_read_qualifiers(char const **fmt)
{
	char                *qualifiers;
	unsigned char		i;
    t_list              *o;
	char				max;
	unsigned char		y;

	i = 0;
    o = NULL;
	max = 0;
	y = 0;
	while (ft_is_in_a(**fmt, (int[4]){'l', 'h', 'z', 'L'}, 4) && ++i)
	{
		if (**fmt == 'l')
			y += 1;
		if (**fmt > max)
			max = **fmt;
		*fmt += 1;	
	}
	qualifiers = malloc(3);
	qualifiers[0] = max;
	if (max == 'h')
		qualifiers[1] = !(i % 2) ? 'h' : 0;
	else
		qualifiers[1] = !(y % 2) ? 'l' : 0;
	qualifiers[2] = 0;
	return (qualifiers);
}


static t_flags	ft_merge_flags(t_flags a, t_flags b)
{
	return ((t_flags) {
		.minus = (a.minus | b.minus),
		.space = (a.space | b.space),
		.zero = (a.zero | b.zero),
		.sharp = (a.sharp | b.sharp),
		.plus = (a.plus | b.plus),
	});
}

char			*ft_argtoa(char const **fmt, va_list ap, int no, t_list **nulls)
{
	t_flags		flags;
	char		*qualifiers;
	char		*swp;
	int			precision;
	int			padding;
	char		specifier;

	padding = 0;
	precision = NO_PRECISION;
	flags = (t_flags) {0,0,0,0,0};
	qualifiers = NULL;
	while (ft_is_in_a(**fmt, (int[10]){'.', '+', '-', '#', ' ', '*', 'l', 'h', 'z', 'L'}, 10) || ft_isdigit(**fmt))
	{
		flags = ft_merge_flags(flags, ft_read_flags(fmt));
		if (ft_isdigit(**fmt) || **fmt == '*')
			padding = ft_read_num(fmt, ap) ;
		if (**fmt == '.')
		{
			precision = 0;
			*fmt += 1;
			if (!ft_isdigit(**fmt) && **fmt != '*')
				continue;
			precision = ft_read_num(fmt, ap);
		}
		if (!(swp = ft_read_qualifiers(fmt)))
			return ((void*)(size_t)(0+ft_free(qualifiers, 0)));
		else if (ft_strlen(swp) || ft_free(swp, 0))
		{
			if (qualifiers)
				free(qualifiers);
			qualifiers = swp;
		}
	}
	if (!qualifiers)
		qualifiers = ft_strdup("");
	return ((ft_is_specifier(specifier = **fmt) ? 
	(ft_get_specifier(specifier))((t_specifier_state) {
    		.flags=flags,
			.qualifiers=qualifiers,
			.specifier=specifier,
        	.padding=padding, 
        	.precision=precision, 
        	.no=no,
            .nulls=nulls,
    	    .force_prefix=FALSE,
        }, ap) + (++*fmt && 0) : ft_strdup("")) + ft_free(qualifiers, 0));
}
