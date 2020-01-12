/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_register_defaults.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:37:30 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 00:22:46 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static char 		*ft_fmt_int(t_fmt_state *state)
{
	int				i;

	i = va_arg(state->args, int);
	return (ft_itoa(i));
}

static char			*ft_fmt_str(t_fmt_state *state)
{
	char			*ptr;

	ptr = va_arg(state->args, char *);
	if (!ptr)
		return (ft_strdup("(null)"));
	else
		return (ft_strdup(ptr));
}

static char			*ft_fmt_char(t_fmt_state *state)
{
	char			c;
	char			*output;

	c = va_arg(state->args, int);
	output = malloc(2 * sizeof(char));
	if (!output)
		return (output);
	output[0] = c;
	output[1] = '\0';
	return (output);
}

static char			*ft_fmt_ptr(t_fmt_state *state)
{
	unsigned long long		addr;
	char					*o;
	char					*swp;

	addr = (unsigned long long) va_arg(state->args, void *);
	o = ft_ubase(b16, addr, ULONG_LONG_MAX);
	if (o)
	{
		swp = ft_strjoin("0x", o);
		free(o);
		o = swp;
	}
	state->output_len += ft_strlen(o);
	return (o);
}

static char			*ft_fmt_hexa(t_fmt_state *state)
{
	unsigned long long		addr;
	char					*o;

	addr = (unsigned long long) va_arg(state->args, void *);
	o = ft_ubase(b16, addr, ULONG_LONG_MAX);
	state->output_len += ft_strlen(o);
	return (o);
}

static char			*ft_fmt_hexac(t_fmt_state *state)
{
	unsigned long long		addr;
	char					*o;

	addr = (unsigned long long) va_arg(state->args, void *);
	o = ft_ubase(B16, addr, ULONG_LONG_MAX);
	state->output_len += ft_strlen(o);
	return (o);
}
t_bool				ft_register_defaults()
{
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'},'i', &ft_fmt_int}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 's', &ft_fmt_str}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'c', &ft_fmt_char}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'p', &ft_fmt_ptr}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'x', &ft_fmt_hexa}))
		return (FALSE);
	if (!ft_register_fmt_id((t_fmt_id){{'\0', '\0'}, 'X', &ft_fmt_hexac}))
		return (FALSE);
	return (TRUE);
}
